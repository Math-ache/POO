#include "../headers/exceptii.h"

const char* hainaInvalida::what() const noexcept
{
    return "Tipul de haina nu este valid!";
}

const char* pretInvalid::what() const noexcept
{
    return "Pretul nu este valid!";
}

const char* inputInvalid::what() const noexcept
{
    return "Inputul nu este valid!";
}