#ifndef NON_HEADER_LOGGER_HPP
# define NON_HEADER_LOGGER_HPP

#include <ostream>
#include "ILogger.hpp"


class NonHeaderLogger : public ILogger
{
private:
    std::ostream&   os;

public:
    NonHeaderLogger(std::ostream& out_stream) : os(out_stream) {

    }
    ~NonHeaderLogger() {

    }

    void    write(std::string message) {
        os << message << "\n";
    }
};

#endif