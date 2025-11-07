#ifndef OUTCON_HPP
#define OUTCON_HPP

#include <iostream>
#include <string>

namespace outcon
{
    class OutputController {
    public:
        static void print(const std::string& message) {
            std::cout << message << std::endl;
        }
        
        static void error(const std::string& message) {
            std::cerr << "ERROR: " << message << std::endl;
        }
        
        static void warning(const std::string& message) {
            std::cout << "WARNING: " << message << std::endl;
        }
        
        static void info(const std::string& message) {
            std::cout << "INFO: " << message << std::endl;
        }
    };
} // namespace outcon

#endif // OUTCON_HPP