#ifndef DATE_HEADER_LOGGER_HPP
# define DATE_HEADER_LOGGER_HPP

#include "HeadlineLogger.hpp"
#include <ctime>

class DateHeaderLogger : public HeadlineLogger
{
private:
    /*data*/

public:
    DateHeaderLogger(ILogger* p_logger) : HeadlineLogger(p_logger) {

    };
    ~DateHeaderLogger() {};

    std::string get_header(void) {
        std::time_t currentTime = std::time(0);
        char    buff[50] = {0};

        std::strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));    
        return (std::string(buff));
    }
};


#endif