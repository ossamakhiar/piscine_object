#ifndef STREAM_LOGGER_HPP
# define STREAM_LOGGER_HPP

#include "ILogger.hpp"
#include <ostream>
#include <ctime>

class StreamLogger : public ILogger
{
private:
	std::ostream&   os;

public:
	StreamLogger(std::ostream& out_stream) : os(out_stream) {

	};

	~StreamLogger() {};

	void    write(std::string message) {
		os << message << "\n";
	}
};




#endif 