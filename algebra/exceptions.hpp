#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

namespace exc
{
    class Exception
    {
    protected:
        std::string message_;

    public:
        explicit Exception(const std::string& msg) noexcept : message_(msg) {}
        const char* what() const noexcept { return message_.c_str(); }
    };

    struct invalid_data : public Exception
    {
        explicit invalid_data(const std::string& msg)
            : Exception("Invalid data: " + msg) {}
    };

    struct division_by_zero : public Exception
    {
        explicit division_by_zero(const std::string& msg)
            : Exception("Division by zero: " + msg) {}
    };

    struct dimension_mismatch : public Exception
    {
        explicit dimension_mismatch(const std::string& msg)
            : Exception("Dimension mismatch: " + msg) {}
    };

    struct unspecified_data : public Exception
    {
        explicit unspecified_data(const std::string& msg)
            : Exception("Unspecified data: " + msg) {}
    };

    struct unknown_data : public Exception
    {
        explicit unknown_data(const std::string& msg)
            : Exception("Unknown data: " + msg) {}
    };

    struct undefined_data : public Exception
    {
        explicit undefined_data(const std::string& msg)
            : Exception("Undefined data: " + msg) {}
    };
} //namespace exc

#endif //EXCEPTION_HPP