#include "MyRuntimeError.hpp"


MyRuntimeError::MyRuntimeError(const std::string& err) : str(err)
{

}

const char* MyRuntimeError::what() const throw()
{
    return (str.c_str());
}