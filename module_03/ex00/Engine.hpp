#ifndef ENGINE_HPP
# define ENGINE_HPP

#include <iostream>


/**
    * @brief The Engine class encapsulates the functionality related to starting and stopping the engine. 
    * It adheres strictly to the Single Responsibility Principle, handling only the specific responsibilities associated with engine control. 
    * Its methods, start() and stop(), precisely reflect its focused role, making it easy to comprehend and maintain.
*/
class Engine
{
public:
    void start() {
        std::cout << "Engine started.\n";
    }

    void stop() {
        std::cout << "Engine stopped.\n";
    }
};

#endif