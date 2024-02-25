#ifndef IHEADER_HPP
# define IHEADER_HPP

#include <string>

class IHeader
{
public:
    virtual std::string get_header() = 0;
    virtual ~IHeader() {};
};

#endif