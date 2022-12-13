#include "../headers/bluza.h"
#include "../headers/exceptii.h"

bluza::bluza() : haina(), gluga(false), inchidere("") {}

bluza::bluza(float pret, const std::string producator, const std::string culoare, const std::string marime, const std::vector<std::string> materiale, bool gluga, const std::string inchidere) : haina(pret, producator, culoare, marime, materiale), gluga(gluga), inchidere(inchidere) {}

bluza::bluza(const bluza &b) : haina(b), gluga(b.gluga), inchidere(b.inchidere) {}

bluza::~bluza() {}

bool bluza::getGluga() const
{
    return gluga;
}

std::string bluza::getInchidere() const
{
    return inchidere;
}

void bluza::setGluga(bool _gluga)
{
    this->gluga = _gluga;
}

void bluza::setInchidere(std::string _inchidere)
{
    this->inchidere = _inchidere;
}

bluza &bluza::operator=(const bluza &b)
{
    if (this != &b)
    {
        haina::operator=(b);
        gluga = b.gluga;
        inchidere = b.inchidere;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const bluza &b)
{
    os << dynamic_cast<const haina &>(b) << "\n"
       << "Gluga: " << b.gluga << "\n"
       << "Inchidere: " << b.inchidere;
    return os;
}

std::istream &operator>>(std::istream &is, bluza &b)
{
    try
    {
        is >> dynamic_cast<haina &>(b);
        std::cout << "Gluga (0 sau 1): ";
        is >> b.gluga;
        std::cout << "Inchidere: ";
        is >> b.inchidere;
    }
    catch (const inputInvalid &e)
    {
        std::cout << e.what() << "\n";
        throw inputInvalid();
    }
    return is;
}

void bluza::descriere()
{
    std::cout << "\nSunt o bluza " << getCuloare() << " " << getProducator() << (getGluga() ? " cu gluga" : " fara gluga") << ", cu inchidere prin " << getInchidere() << ", marimea " << getMarime() << ", in valoare de " << getPret() << " lei, facuta din: ";

    for (size_t i = 0; i < getMateriale().size(); i++)
    {
        if (i == 0)
            std::cout << getMateriale()[i];
        else
            std::cout << ", " << getMateriale()[i];
    }
    std::cout << ".\n";
}