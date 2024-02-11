#include "uncomPngWriter.hpp"

UncomPngWriter::UncomPngWriter(uint32_t  h, uint32_t w, std::string output) : height(h), width(w), idat_length(0), output_path(output) 
{
    std::cout << "Constructing the png writer\n";

    if (width == 0 || height == 0 ||
		width > 500 || height > 500)
			throw std::runtime_error("width and height of the image should be between 1, 500");

	x_pos = y_pos = 0;
	this->data_size = 0;

	image_truecolor.resize(height);
	for (size_t i = 0; i < height; ++i)
		image_truecolor[i].resize(width * 3 + 1);

	png_output.open(output_path, std::ios::out | std::ios::binary);
	if (!png_output.is_open())
		throw std::runtime_error("Can't open the file: " + output);

	writeIHDR(height, width);
	calculate_idat_length();
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

	if (x < 0 || y < 0 || (uint32_t)x >= width || (uint32_t)y >= height)
		throw std::runtime_error("bad pixel position");
	red = pixel_color >> 16;
	green = pixel_color >> 8;
	blue = pixel_color >> 0;

	offset = x * 3;
	// * i added one due the fact that the first byte at the row is filter byte
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

uint8_t*	UncomPngWriter::get_deflate_header(bool last_block, uint16_t block_size)
{
	uint8_t*	deflate_hdr = new uint8_t[5];

	deflate_hdr[0] = last_block ? 1 : 0;
	deflate_hdr[1] = block_size & 0xff;
	deflate_hdr[2] = block_size >> 8;
	deflate_hdr[3] = ~deflate_hdr[1];
	deflate_hdr[4] = ~deflate_hdr[2];

	return (deflate_hdr);
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


void    UncomPngWriter::writeIHDR(uint32_t height, uint32_t width)
{
	uint8_t	header[] = {
		// magic bytes - signature
		0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A,
		// IHDR chunk
		// chunk data length (constant 13 bytes)
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
	};

	put_bytes_big_endian(width, &header[16]);
	put_bytes_big_endian(height, &header[20]);

	crc.reset();
	crc.crc_update(&header[12], 17);
	put_bytes_big_endian(crc.get_crc_value(), &header[29]);

	// ? write the png header into the output file
	bytes_writer(header, 33);
}


void	UncomPngWriter::prepareIDAT()
{
	uint8_t	start_idat[] = {
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

	put_bytes_big_endian(idat_length, &start_idat[0]);

	// ! reseting crc to start with IDAT bytes data
	crc.reset();
	crc.crc_update(&start_idat[4], 6);
	bytes_writer(start_idat, 10);
}



void	UncomPngWriter::block_writer(uint16_t bytes_to_write)
{

	uint16_t	rows = bytes_to_write / (width * 3 + 1);

	while (rows--)
	{
		bytes_writer(&image_truecolor[y_pos][0], width * 3 + 1);
		crc.crc_update(&image_truecolor[y_pos][0], width * 3 + 1);
		adler.checksum(&image_truecolor[y_pos][0], width * 3 + 1);

		y_pos++;
		data_size -= (width * 3) + 1;
	}
}

void	UncomPngWriter::writeIDAT()
{
	uint8_t		adler_be[4] = {0x0, 0x0, 0x0, 0x0}; // adler checksum in big endian
	uint8_t		crc_be[4] = {0x0, 0x0, 0x0, 0x0};
	uint32_t	block_nums;
	uint16_t	size, block_size, row_size;

	// ** DEFLATE_MAX_BLOCK_SIZE is the maximum size of a DEFLATE block,
	// ** and dividing it by the row size (width * 3 + 1) gives the number of rows that can fit into a block
	// ** The goal is to create blocks that are as large as possible

	row_size = (width * 3 + 1); // every pixel consist of 3 bytes and +1 for fillter byte
	size = (DEFLATE_MAX_BLOCK_SIZE / row_size) * row_size;
	block_nums = data_size / size + (data_size % size != 0);

	for (uint32_t i = 0; i < block_nums; ++i)
	{
		block_size = (i == block_nums - 1) ? data_size : size;
		uint8_t*	deflate_header = get_deflate_header(i == block_nums - 1, block_size);

		crc.crc_update(deflate_header, 5);
		bytes_writer(deflate_header, 5);

		block_writer(block_size);
		delete[]	deflate_header;
	}

	// ! writing adler checksum at the end of the DEFLATE
	put_bytes_big_endian(adler.get_adler(), &adler_be[0]);
	bytes_writer(adler_be, 4);

	// ! update crc value, and write it at the end of IDAT chunk
	crc.crc_update(&adler_be[0], 4);
	put_bytes_big_endian(crc.get_crc_value(), &crc_be[0]);
	bytes_writer(crc_be, 4);
}

void    UncomPngWriter::save_image()
{
	prepareIDAT();
	writeIDAT();

	uint8_t footer[] = {
		// IEND chunk
		0x00, 0x00, 0x00, 0x00,
		0x49, 0x45, 0x4E, 0x44,
		0xAE, 0x42, 0x60, 0x82,
	};

	bytes_writer(footer, 12);
}





void	UncomPngWriter::bytes_writer(uint8_t *data, uint32_t n)
{
	if (!data)
		throw std::runtime_error("Unable to write, The provided data is null or invalid");
	png_output.write(reinterpret_cast<const char *>(data), n);
}


/***
 * @brief Converts a 32-bit (4 bytes) little-endian value to big-endian and stores it in a contiguous memory location.
 * @param v The little-endian value to be converted
 * @param mem The memory location to store the result in big-endian format
 * @throws std::runtime_error if the provided memory address is invalid (nullptr)
 */
void	UncomPngWriter::put_bytes_big_endian(uint32_t v, uint8_t *mem)
{
	if (!mem)
		throw std::runtime_error("bad address");

	mem[0] = v >> 24; // *Most significant byte at the smallest mem address
	mem[1] = v >> 16;
	mem[2] = v >> 8;
	mem[3] = v; // *Least significant byte at the highest mem address
}


int	UncomPngWriter::big_endian(int le)
{
	int			ret = 0;
	uint8_t*	mem = reinterpret_cast<uint8_t*>(&le);

	ret = mem[0] << 24;
	ret |= mem[1] << 16;
	ret |= mem[2] << 8;
	ret |= mem[3] << 0;

	return (ret);
}
