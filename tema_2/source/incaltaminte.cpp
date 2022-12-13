#include "../headers/incaltaminte.h"
#include "../headers/exceptii.h"

incaltaminte::incaltaminte() : haina(), grosimeTalpa(0), model("")
{
}

incaltaminte::incaltaminte(float pret, std::string producator, std::string culoare, std::string marime, std::vector<std::string> materiale, float grosimeTalpa, std::string model) : haina(pret, producator, culoare, marime, materiale), grosimeTalpa(grosimeTalpa), model(model)
{
}

incaltaminte::incaltaminte(const incaltaminte &i) : haina(i), grosimeTalpa(i.grosimeTalpa), model(i.model)
{
}

incaltaminte::~incaltaminte()
{
}

float incaltaminte::getGrosimeTalpa() const
{
    return grosimeTalpa;
}

std::string incaltaminte::getModel() const
{
    return model;
}

void incaltaminte::setGrosimeTalpa(float grosimeTalpa)
{
    this->grosimeTalpa = grosimeTalpa;
}

void incaltaminte::setModel(std::string model)
{
    this->model = model;
}

incaltaminte &incaltaminte::operator=(const incaltaminte &i)
{
    if (this != &i)
    {
        haina::operator=(i);
        grosimeTalpa = i.grosimeTalpa;
        model = i.model;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const incaltaminte &i)
{
    os << dynamic_cast<const haina &>(i) << "Grosime talpa: " << i.grosimeTalpa << "\n"
       << "Model: " << i.model << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, incaltaminte &i)
{
    try
    {
        is >> dynamic_cast<haina &>(i);
        std::cout << "Grosime talpa: ";
        is >> i.grosimeTalpa;
        std::cout << "Model: ";
        is >> i.model;
    }
    catch(const inputInvalid &e)
    {
        std::cout << e.what() << '\n';
        throw inputInvalid();
    }
    return is;
}

void incaltaminte::descriere()
{
    std::cout << "\nSunt o pereche de " << getModel() << " " << getProducator() << " " << getCuloare() << ", "
              << "marimea " << getMarime() << " cu grosimea talpii de " << getGrosimeTalpa() << " cm,"
              << "in valoare de " << getPret() << " lei, confectionata din: ";

    for (size_t i = 0; i < getMateriale().size(); i++)
    {
        if (i == 0)
            std::cout << getMateriale()[i];
        else
            std::cout << ", " << getMateriale()[i];
    }
    std::cout << ".\n";
}