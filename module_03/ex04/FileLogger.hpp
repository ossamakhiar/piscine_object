#ifndef FILE_LOGGER_HPP
# define FILE_LOGGER_HPP

#include <fstream>
#include <ctime>
#include "ILogger.hpp"
#include "IHeader.hpp"

class FileLogger : public ILogger
{
private:
    IHeader&        _header_provider;
    std::ofstream   fout;

public:
    FileLogger(IHeader& header_provider) : _header_provider(header_provider) {
        std::string name = "demo.log";
    
        fout.open(name.c_str(), std::fstream::out | std::fstream::app);
        if (!fout.is_open())
            throw   std::runtime_error("Can't open the file");
    };
    ~FileLogger() {
        fout.close();
    };

    void    write(std::string message) {
        fout << _header_provider.get_header() << " ";
        fout << message << "\n";
    }
};


#endif