#include "../headers/pantaloni.h"
#include "../headers/exceptii.h"

pantaloni::pantaloni() : haina(), curea(false), lungime("") {}

pantaloni::pantaloni(float pret, std::string producator, std::string culoare, std::string marime, std::vector<std::string> materiale, bool curea, std::string lungime) : haina(pret, producator, culoare, marime, materiale), curea(curea), lungime(lungime) {}

pantaloni::pantaloni(const pantaloni &p) : haina(p), curea(p.curea), lungime(p.lungime) {}

pantaloni::~pantaloni() {}

bool pantaloni::getCurea() const
{
    return curea;
}

std::string pantaloni::getLungime() const
{
    return lungime;
}

void pantaloni::setCurea(bool _curea)
{
    this->curea = _curea;
}

void pantaloni::setLungime(std::string _lungime)
{
    this->lungime = _lungime;
}

pantaloni &pantaloni::operator=(const pantaloni &p)
{
    if (this != &p)
    {
        haina::operator=(p);
        curea = p.curea;
        lungime = p.lungime;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const pantaloni &p)
{
    os << dynamic_cast<const haina &>(p) << "Cu curea: " << (p.curea ? "Cu curea" : "Fara curea") << ", lungime: " << p.lungime;
    return os;
}

std::istream &operator>>(std::istream &is, pantaloni &p)
{
    try
    {
        is >> dynamic_cast<haina &>(p);
        std::cout << "Curea (0 sau 1): ";
        is >> p.curea;
        std::cout << "Lungime: ";
        is >> p.lungime;
    }
    catch (const inputInvalid &e)
    {
        std::cout << e.what() << '\n';
        throw inputInvalid();
    }
    return is;
}

void pantaloni::descriere()
{
    std::cout << "\nSunt o pereche de pantaloni " << getCuloare() << " " << getProducator() << ", " << getLungime() << "," << (getCurea() ? " cu curea" : " fara curea") << ", marimea " << getMarime() << ", in valoare de " << getPret() << " lei, din materiale: ";
    for (size_t i = 0; i < getMateriale().size(); i++)
    {
        if (i == 0)
            std::cout << getMateriale()[i];
        else
            std::cout << ", " << getMateriale()[i];
    }
    std::cout << ".\n";
}
