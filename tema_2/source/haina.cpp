#include "../headers/haina.h"
#include "../headers/exceptii.h"

haina::haina() : pret(0), producator(""), culoare(""), marime(""), materiale(std::vector<std::string>()) {}

haina::haina(float pret, const std::string &producator, const std::string &culoare, const std::string &marime, const std::vector<std::string> &materiale) : pret(pret), producator(producator), culoare(culoare), marime(marime), materiale(materiale) {}

haina::haina(const haina &h) : pret(h.pret), producator(h.producator), culoare(h.culoare), marime(h.marime), materiale(h.materiale) {}

haina::~haina() {}

float haina::getPret() const
{
    return pret;
}

std::string haina::getProducator() const
{
    return producator;
}

std::string haina::getCuloare() const
{
    return culoare;
}

std::string haina::getMarime() const
{
    return marime;
}

std::vector<std::string> haina::getMateriale() const
{
    return materiale;
}

void haina::setPret(float _pret)
{
    this->pret = _pret;
}

void haina::setProducator(std::string _producator)
{
    this->producator = _producator;
}

void haina::setCuloare(std::string _culoare)
{
    this->culoare = _culoare;
}

void haina::setMarime(std::string _marime)
{
    this->marime = _marime;
}

void haina::setMateriale(std::vector<std::string> _materiale)
{
    this->materiale = _materiale;
}

haina &haina::operator=(const haina &h)
{
    if (this != &h)
    {
        this->pret = h.pret;
        this->producator = h.producator;
        this->culoare = h.culoare;
        this->marime = h.marime;
        this->materiale = h.materiale;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const haina &h)
{
    os << "Producator: " << h.producator << "\n"
       << "Culoarea: " << h.culoare << "\n"
       << "Marime: " << h.marime << "\n"
       << "Pret: " << h.pret << "\n";

    os << "Materiale: ";
    for (auto &material : h.materiale)
    {
        os << material << " ";
    }
    os << "\n";

    return os;
}

std::istream &operator>>(std::istream &is, haina &h)
{
    try
    {
        int pretAux;
        std::cout << "Pret: ";
        is >> pretAux;
        if (pretAux <= 0)
            throw pretInvalid();

        h.pret = pretAux;
        std::cout << "Producator: ";
        is >> h.producator;
        std::cout << "Culoarea: ";
        is >> h.culoare;
        std::cout << "Marime: ";
        is >> h.marime;

        int nrMateriale;
        std::cout << "Nr materiale: ";
        is >> nrMateriale;
        std::cout << "Materiale: ";
        for (int i = 0; i < nrMateriale; i++)
        {
            std::string material;
            is >> material;
            h.materiale.push_back(material);
        }
    }
    catch (const pretInvalid &e)
    {
        std::cout << e.what() << '\n';
        throw inputInvalid();
    }

    return is;
}