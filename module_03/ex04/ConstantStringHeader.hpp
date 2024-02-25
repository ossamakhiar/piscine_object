#ifndef CONSTANT_STRING_HEADER_HPP
# define CONSTANT_STRING_HEADER_HPP

#include "IHeader.hpp"

class   ConstantStringHeader : public IHeader
{
private:
    std::string _header;

public:
    ConstantStringHeader(const std::string& header) : _header(header) {};
    ~ConstantStringHeader() {};

    std::string get_header() {
        return (_header);
    }
};


#endif