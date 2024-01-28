#include "adler32.hpp"


Adler32::Adler32()
{
    bytes_sum = 0x1;
    step_sum = 0x0;
    adler = 0x0;
}

Adler32::~Adler32()
{
    // * Destructor code if needed.
}

uint32_t	Adler32::get_adler() const
{
    return (adler);
}

void	Adler32::reset()
{
    bytes_sum = 0x1;
    step_sum = 0x0;
    adler = 0x0;
}

void	Adler32::checksum(uint8_t *data, size_t len)
{
    // * Adler-32 checksum calculation.
	for (size_t i = 0; i < len; i++)
	{
		bytes_sum = (bytes_sum + data[i]) % MOD_ADLER;
		step_sum = (step_sum + bytes_sum) % MOD_ADLER;
	}
	adler = (step_sum << 16) | bytes_sum;
}