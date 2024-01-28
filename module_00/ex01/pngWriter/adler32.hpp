#ifndef ADLER32_HPP
# define ADLER32_HPP

#include <iostream>
#include <cstdint>

#define MOD_ADLER 65521

class Adler32
{
private:
	uint32_t	adler;
	uint32_t	bytes_sum;
	uint32_t	step_sum;

public:
	Adler32();
	~Adler32();

	uint32_t	get_adler() const;

	void	reset();
	void	checksum(uint8_t	*data, size_t len);
};


#endif