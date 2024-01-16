#include "MyRuntimeError.hpp"


MyRuntimeError::MyRuntimeError(const std::string& err) : str(err)
{

}

const char* MyRuntimeError::what() const
{
    return (str.c_str());
}