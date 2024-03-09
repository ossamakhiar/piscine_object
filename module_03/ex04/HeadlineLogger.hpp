#ifndef HEADLINE_LOGGER_HPP
# define HEADLINE_LOGGER_HPP

#include "ILogger.hpp"
#include <string>

class HeadlineLogger : public ILogger
{
private:
    ILogger& logger;

public:
    HeadlineLogger(ILogger& log) : logger(log) {

    }

    void    write(std::string msg) {
        logger.write(get_header() + msg);
    }

    virtual std::string get_header() = 0;
};

#endif