#include "uncomPngWriter.hpp"

UncomPngWriter::UncomPngWriter(uint32_t  h, uint32_t w, std::string output) : height(h), width(w), idat_length(0), output_path(output) 
{
    std::cout << "Constructing the png writer\n";

	// offset = 0;
	x_pos = y_pos = 0;
	this->data_size = 0;

    if (width == 0 || height == 0 ||
		width > 500 || height > 500)
			throw std::runtime_error("width and height of the image should be between 1, 500");

	image_truecolor.resize(height);
	for (size_t i = 0; i < height; ++i)
		image_truecolor[i].resize(width * 3 + 1);

	png_output.open(output_path, std::ios::out | std::ios::binary);

	if (!png_output.is_open())
		throw std::runtime_error("Can't open the file: " + output);;
	calculate_idat_length();
	headerWriting();
}


UncomPngWriter::UncomPngWriter(const UncomPngWriter& other)
{
	(void)other;
}

UncomPngWriter::~UncomPngWriter()
{

}


void    UncomPngWriter::put_pixel(int x, int y, uint32_t pixel_color)
{
	int		offset = 0;
	uint8_t	red, green, blue;

	if (x < 0 || y < 0)
		throw std::runtime_error("bad pixel position");
	red = pixel_color >> 16;
	green = pixel_color >> 8;
	blue = pixel_color >> 0;

	offset = x * 3;
	image_truecolor[y][offset + 1] = red;
	image_truecolor[y][offset + 2] = green;
	image_truecolor[y][offset + 3] = blue;
}

void    UncomPngWriter::put_pixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
	uint32_t	pixel_color;

	pixel_color = (static_cast<uint32_t>(red) << 16) |
					(static_cast<uint32_t>(green) << 8) |
					(static_cast<uint32_t>(blue));
	put_pixel(x, y, pixel_color);
}

uint32_t UncomPngWriter::get_pixel(int x, int y)
{
    int offset = x * 3 + 1;  // Assuming filter byte is at index 0

    uint8_t red = image_truecolor[y][offset];
    uint8_t green = image_truecolor[y][offset + 1];
    uint8_t blue = image_truecolor[y][offset + 2];

    uint32_t pixel_color = (static_cast<uint32_t>(red) << 16) |
                           (static_cast<uint32_t>(green) << 8) |
                           (static_cast<uint32_t>(blue));

    return pixel_color;
}

void    UncomPngWriter::put_color_map(std::vector<uint8_t> pixel_map)
{
	(void)pixel_map;
}

void	UncomPngWriter::calculate_idat_length(void)
{
	uint32_t	block_nums;

	data_size = width * 3 + 1; // line size rgb and filter byte

	// if (data_size >= UINT16_MAX)
	if (data_size >= DEFLATE_MAX_BLOCK_SIZE)
		throw std::runtime_error("image is too large");

	data_size *= height;
	if (data_size >= UINT32_MAX)
		throw std::runtime_error("image is too large");

	block_nums = data_size / DEFLATE_MAX_BLOCK_SIZE;
	if (data_size % DEFLATE_MAX_BLOCK_SIZE != 0)
		block_nums++;

	//Each DEFLATE uncompressed block header requires 5 bytes, the zlib header takes 2 bytes, and the zlib Adler-32 footer consumes 4 bytes
	idat_length = block_nums * 5 + 6 + data_size;
	if (idat_length >= UINT32_MAX)
		throw std::runtime_error("Image too large");
}


void	UncomPngWriter::headerWriting(void)
{
	uint8_t	header[] = {
		// magic signature
		0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A,
		// IHDR chunk
		// chunk data lebgth
		0x0, 0x0, 0x0, 0x0D,
		// IHDR ascii values
		0x49, 0x48, 0x44, 0x52,
		// Width
		0x0, 0x0, 0x0, 0x0,
		// height
		0x0, 0x0, 0x0, 0x0,
		// bpp _ + color type (rgb == 2) + compression method (DEFLATE = 0)
		0x08, 0x02, 0x0, 
		// filter method (0 indicate no filter applied) + Interlace method
		0x0, 0x0,
		0x0, 0x0, 0x0, 0x0,  // IHDR CRC-32 placeholder
		// IDAT Chunk
		0x0, 0x0, 0x0, 0x0, // length place holder
		0x49, 0x44, 0x41, 0x54, // IDAT ascii
		// ZLIB Header 
		/*
		 0   1   	 Within the 8 bits, the first 4 bits (CM 0-3) represent the compression method,
		+---+---+  / where a value of 8 indicates the use of the Deflate method. The next 4 bits (4-7) denote the window size, storing log2(size) - 8
		|CMF|FLG| /
		+---+---+ \ FLG 8bits, 0-4 contains check sum = 31 - (CMF * 256 + FLG) % 31; bit 5 FDICT, 6-7 COMP LEVEL 
		*/
		0x08, 0x1d,
		// deflate compressed data format
		};

	put_bytes_big_endian(width, &header[16]);
	put_bytes_big_endian(height, &header[20]);

	// * calculate CRC of IHDR chunk
	crc.reset();
	crc.crc_update(&header[12], 17);
	put_bytes_big_endian(crc.get_crc_value(), &header[29]);

	put_bytes_big_endian(idat_length, &header[33]);

	crc.reset();
	crc.crc_update(&header[37], 6);
	bytes_writer(header, 43);
}


void	UncomPngWriter::put_bytes_big_endian(uint32_t v, uint8_t *mem)
{
	mem[0] = v >> 24;
	mem[1] = v >> 16;
	mem[2] = v >> 8;
	mem[3] = v;
}

void	UncomPngWriter::block_writer(uint16_t bytes_to_write)
{

	uint16_t	rows = bytes_to_write / (width * 3 + 1);

	// std::cout << "rows: " << rows << "\n";
	// std::cout << "remainder: " << bytes_to_write % (width * 3 + 1) << "\n"; // should be zero.
	while (rows--)
	{
		// for (int i = 0; i <= width * 3; ++i)
		// 	std::cout << std::hex << "0x" << (int)(image_truecolor[y_pos][i]) << " ";
		// std::cout << "\n";
		bytes_writer(&image_truecolor[y_pos][0], width * 3 + 1);
		crc.crc_update(&image_truecolor[y_pos][0], width * 3 + 1);
		adler.checksum(&image_truecolor[y_pos][0], width * 3 + 1);

		y_pos++;
		data_size -= (width * 3) + 1;
	}
}

void    UncomPngWriter::save_image()
{
	uint32_t	block_nums;
	uint16_t	size, block_size;

	// ** DEFLATE_MAX_BLOCK_SIZE is the maximum size of a DEFLATE block,
	// ** and dividing it by the row size (width * 3 + 1) gives the number of rows that can fit into a block
	// ** The goal is to create blocks that are as large as possible

	size = (DEFLATE_MAX_BLOCK_SIZE / (width * 3 + 1)) * (width * 3 + 1);
	block_nums = data_size / size + (data_size % size != 0);

	// std::cout << "appropriate size of block: " << size << "\n";
	// std::cout << "block_nums: " << block_nums << "\n";
	for (uint32_t i = 0; i < block_nums; ++i)
	{
		block_size = (i == block_nums - 1) ? data_size : size;
		uint8_t deflate_header[] = {  // 5 bytes long
			static_cast<uint8_t>(i == block_nums - 1),
			static_cast<uint8_t>(block_size >> 0),
			static_cast<uint8_t>(block_size >> 8),
			static_cast<uint8_t>((block_size >> 0) ^ 0xFF),
			static_cast<uint8_t>((block_size >> 8) ^ 0xFF),
		};
		crc.crc_update(deflate_header, 5);
		bytes_writer(deflate_header, 5);

		block_writer(block_size);
	}

	uint8_t footer[] = {  // 20 bytes long
		0, 0, 0, 0,  // DEFLATE Adler-32 placeholder
		0, 0, 0, 0,  // IDAT CRC-32 placeholder
		// IEND chunk
		0x00, 0x00, 0x00, 0x00,
		0x49, 0x45, 0x4E, 0x44,
		0xAE, 0x42, 0x60, 0x82,
	};

	put_bytes_big_endian(adler.get_adler(), &footer[0]);
	crc.crc_update(&footer[0], 4);
	put_bytes_big_endian(crc.get_crc_value(), &footer[4]);
	bytes_writer(footer, 20);
}


void	UncomPngWriter::bytes_writer(uint8_t *data, uint32_t n)
{
	png_output.write(reinterpret_cast<const char *>(data), n);
}
