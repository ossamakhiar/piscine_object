/************************************/
/** Dependency Inversion Principle **/
/************************************/

#include "DateHeader.hpp"
#include "ConstantStringHeader.hpp"
#include "StreamLogger.hpp"
#include "FileLogger.hpp"
#include "NonHeaderLogger.hpp"
#include <unistd.h>
#include <vector>


int main(void)
{
    DateHeader                  date_header;
    ConstantStringHeader        const_str_header("[***HEADER***]");
    std::vector<ILogger*>       loggers;
    std::vector<std::string>    msgs;

    std::ofstream   out("nonHeader.log");
    

    loggers.push_back(new StreamLogger(std::cout, const_str_header));
    loggers.push_back(new FileLogger(date_header));
    loggers.push_back(new NonHeaderLogger(out));

    msgs.push_back("Message 1..");
    msgs.push_back("Message 2..");
    msgs.push_back("Message 3..");

    for (size_t j = 0; j < msgs.size(); j++)
        for (size_t i = 0; i < loggers.size(); i++)
            loggers[i]->write(msgs[j]);

    out.close();
    for (std::vector<ILogger*>::iterator it = loggers.begin(); it != loggers.end(); it++)
        delete  (*it);
    return (0);
}