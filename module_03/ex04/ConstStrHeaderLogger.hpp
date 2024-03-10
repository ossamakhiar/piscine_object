#ifndef CONST_STR_HEADER_LOGGER_HPP
# define CONST_STR_HEADER_LOGGER_HPP

#include "HeadlineLogger.hpp"

class   ConstStrHeaderLogger : public HeadlineLogger
{
private:
    std::string _header;

public:
    ConstStrHeaderLogger(const std::string& header, ILogger* logger) : HeadlineLogger(logger), _header(header) {

    };

    ~ConstStrHeaderLogger() {};


    std::string get_header() {
        return (_header);
    }
};


#endif