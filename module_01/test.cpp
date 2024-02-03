#include <iostream>
#include <iomanip>

int main(void)
{
    std::cout << std::setw(20) << std::left << "hello world" << ";\n";
    return (0);
}

/*
Resvirsing bits
def rbit32(val):
 val = ((val & 0x55555555)<<1) | ((val & 0xaaaaaaaa)>>1)
 val = ((val & 0x33333333)<<2) | ((val & 0xcccccccc)>>2)
 val = ((val & 0x0f0f0f0f)<<4) | ((val & 0xf0f0f0f0)>>4)
 val = ((val & 0x00ff00ff)<<8) | ((val & 0xff00ff00)>>8)
 val = ((val & 0x0000ffff)<<16) | ((val & 0xffff0000)>>16)
 return val
*/