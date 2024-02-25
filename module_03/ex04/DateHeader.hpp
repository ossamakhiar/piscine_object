#ifndef DATE_HEADER_HPP
# define DATE_HEADER_HPP

#include "IHeader.hpp"
#include <ctime>

class DateHeader : public IHeader
{
    // ? maybe it better to store the message inside the DateHeader class and in case of writing the Logger just pass 
public:
    DateHeader() {

    };
    ~DateHeader() {};

    std::string get_header(void) {
        std::time_t currentTime = std::time(0);
        char    buff[50] = {0};

        std::strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));    
        return (std::string(buff));
    }
};


#endif