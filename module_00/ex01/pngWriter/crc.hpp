#ifndef CRC_HPP
# define CRC_HPP

#include <iostream>
#include <cstdint>
#include <stdexcept>

// TODO :: Perhaps extend it and structure the CRC bit value to be generated based on a template value...
class Crc
{
private:
    static const uint32_t  polynomial = 0xEDB88320;
    uint32_t  crc; // remainder of the polynomial division

public:
    Crc();
    ~Crc();

    uint32_t    get_crc_value() const;

    void    reset();
    void    crc_update(uint8_t  *data, uint32_t bytes);

};

#endif