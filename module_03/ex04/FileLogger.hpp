#ifndef FILE_LOGGER_HPP
# define FILE_LOGGER_HPP

#include <fstream>
#include <ctime>
#include "ILogger.hpp"

class FileLogger : public ILogger
{
private:
    std::ofstream   fout;

public:
    FileLogger() {
        std::string name = "demo.log";
    
        fout.open(name.c_str(), std::fstream::out | std::fstream::app);
        if (!fout.is_open())
            throw   std::runtime_error("Can't open the file");
    };
    ~FileLogger() {
        fout.close();
    };

    void    write(std::string message) {
        fout << message << "\n";
    }
};


#endif