#include "crc.hpp"

Crc::Crc() : crc(0x0)
{

}

Crc::~Crc()
{

}

uint32_t    Crc::get_crc_value() const
{
    return (crc);
}

void    Crc::reset()
{
    crc = 0x0;
}


// TODO :: implement table lookup method

void	Crc::crc_update(uint8_t  *data, uint32_t bytes)
{
	if (!data || !bytes)
		std::runtime_error("invalid input to crc algo");
	crc = ~crc;
	for (uint32_t i = 0; i < bytes; ++i)
	{
		crc ^= data[i];
		for (uint8_t	j = 0; j < 8; ++j)
			crc = (crc >> 1) ^ (crc & 1 ? polynomial : 0);
	}
	crc = ~crc;
}