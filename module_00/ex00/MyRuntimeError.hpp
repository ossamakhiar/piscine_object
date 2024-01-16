#ifndef MY_RUNTIME_ERROR_HPP
# define MY_RUNTIME_ERROR_HPP

#include <stdexcept>
#include <string>

class MyRuntimeError : public std::exception {

private:
    std::string str;

public:
    MyRuntimeError(const std::string& err);

    const char* what() const throw();
};

#endif