#ifndef UNCOM_PNG_WRITER_HPP
#define UNCOM_PNG_WRITER_HPP

#include <cstdint>
#include <iostream>
#include <fstream>
#include <vector>
#include "crc.hpp"
// #include <cstdlib>
#include "adler32.hpp"
#include <cstdint>

#define DEFLATE_MAX_BLOCK_SIZE UINT16_MAX

// RawPNGWriter

class UncomPngWriter
{
private:

    // uint32_t                offset;

    int						            x_pos, y_pos;
    uint32_t                            block_nums;
    uint16_t                            max_block_size;
    uint16_t                            row_size;
	uint32_t				            data_size;
    Crc						            crc;
    Adler32					            adler;
    uint32_t                            height;
    uint32_t				            width;
    uint32_t				            idat_length;
    std::string				            output_path;
    std::ofstream			            png_output;
    std::vector<std::vector<uint8_t> >	image_truecolor;

    // * should add allocate uint8_t (maybe for performance)???

    uint8_t*    get_deflate_header(bool last_block, uint16_t block_size);
    void	    calculate_idat_length(void);
    void        writeIHDR(uint32_t height, uint32_t width);
    void        prepareIDAT();
    void	    writeIDAT();

    uint32_t	calc_block_nums();
    void	    block_writer(uint16_t bytes_to_write);

    void	put_bytes_big_endian(uint32_t v, uint8_t *mem);
    int     big_endian(int le);
    void	bytes_writer(uint8_t *data, uint32_t n);



public:
    UncomPngWriter(uint32_t  height, uint32_t width, std::string output_path);
    UncomPngWriter(const UncomPngWriter& other);
    ~UncomPngWriter();


    void    put_pixel(int x, int y, uint32_t pixel_color);
    void    put_pixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    void    put_color_map(std::vector<uint8_t> pixel_map);

    // utils

    uint32_t	get_pixel(int x, int y);
    void        save_image();
};

#endif