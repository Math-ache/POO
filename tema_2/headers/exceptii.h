#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>

class hainaInvalida : public std::exception
{
    public:
        const char *what () const noexcept override;
};

class pretInvalid : public std::exception
{
    public:
        const char *what () const noexcept override;
};

class inputInvalid : public std::exception
{
    public:
        const char *what () const noexcept override;
};

#endif // EXCEPTII_H