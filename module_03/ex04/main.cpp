/************************************/
/** Dependency Inversion Principle **/
/************************************/

#include "StreamLogger.hpp"
#include "FileLogger.hpp"
#include "DateHeaderLogger.hpp"
#include "ConstStrHeaderLogger.hpp"
#include <unistd.h>
#include <vector>

// !! BAD Implementation


int main(void)
{
    std::vector<ILogger*>       loggers;
    std::vector<std::string>    msgs;

    // std::ofstream   out("nonHeader.log");
    
    FileLogger      *fileLogger = new FileLogger();
    StreamLogger    *streamLogger = new StreamLogger(std::cout);

    loggers.push_back(fileLogger);
    loggers.push_back(streamLogger);
    loggers.push_back(new DateHeaderLogger(fileLogger));
    loggers.push_back(new ConstStrHeaderLogger("[****HEADER****]", streamLogger));


    msgs.push_back("Message 1..");
    msgs.push_back("Message 2..");
    msgs.push_back("Message 3..");

    for (size_t i = 0; i < loggers.size(); i++)
        for (size_t j = 0; j < msgs.size(); j++)
            loggers[i]->write(msgs[j]);

    // out.close();
    for (std::vector<ILogger*>::iterator it = loggers.begin(); it != loggers.end(); it++)
        delete  (*it);
    return (0);
}