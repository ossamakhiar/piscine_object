#ifndef STREAM_LOGGER_HPP
# define STREAM_LOGGER_HPP

#include "ILogger.hpp"
#include "IHeader.hpp"
#include <ostream>
#include <ctime>

class StreamLogger : public ILogger
{
private:
	std::ostream&   os;
	IHeader&		_header_provider;

public:
	StreamLogger(std::ostream& out_stream, IHeader& header_provider) : os(out_stream), _header_provider(header_provider) {

	};
	~StreamLogger() {};

	void    write(std::string message) {
		os << _header_provider.get_header() << " ";
		os << message << "\n";
	}
};




#endif 