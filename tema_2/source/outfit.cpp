#include "../headers/outfit.h"

outfit::outfit() : haine(std::vector<std::shared_ptr<haina>>()) {}

outfit::outfit(std::vector<std::shared_ptr<haina>> haine, float pretTotal) : haine(haine), pretTotal(pretTotal) {}

outfit::outfit(const outfit &o) : haine(o.haine), pretTotal(o.pretTotal) {}

outfit::~outfit() {}

std::vector<std::shared_ptr<haina>> outfit::getHaine() const
{
    return haine;
}

float outfit::getPretTotal() const
{
    return pretTotal;
}

void outfit::setHaine(std::vector<std::shared_ptr<haina>> _haine)
{
    this->haine = _haine;
}

void outfit::adaugaHaina(std::shared_ptr<haina> h)
{
    haine.push_back(h);
}

void outfit::calculeazaPretTotal()
{
    pretTotal = 0;
    for (auto &h : haine)
    {
        pretTotal += h->getPret();
    }
}

outfit &outfit::operator=(const outfit &o)
{
    if (this != &o)
    {
        haine = o.haine;
        pretTotal = o.pretTotal;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const outfit &o)
{
    os << "\nOutfitul contine urmatoarele haine:\n";
    for (const auto &h : o.haine)
    {
        os << *h;
        if (dynamic_cast<bluza *>(h.get()))
        {
            os << "Gluga: " << (dynamic_cast<bluza *>(h.get())->getGluga() ? "cu gluga" : "fara gluga") << '\n'
               << "Inchidere: " << dynamic_cast<bluza *>(h.get())->getInchidere() << '\n';
        }
        else if (dynamic_cast<pantaloni *>(h.get()))
        {
            os << "Curea: " << (dynamic_cast<pantaloni *>(h.get())->getCurea() ? "cu curea" : "fara curea") << '\n'
               << "Lungime: " << dynamic_cast<pantaloni *>(h.get())->getLungime() << '\n';
        }
        else if (dynamic_cast<incaltaminte *>(h.get()))
        {
            os << "Model: " << dynamic_cast<incaltaminte *>(h.get())->getModel() << '\n'
               << "Grosime talpa: " << dynamic_cast<incaltaminte *>(h.get())->getGrosimeTalpa() << '\n';
        }
    }
    os << "\n";
    return os;
}
std::istream &operator>>(std::istream &is, outfit &o)
{
    int nrHaine;
    std::cout << "Nr haine: ";
    is >> nrHaine;
    for (int j = 0; j < nrHaine; j++)
    {
        std::cout << "Tipul hainei (bluza, pantaloni, incaltaminte): ";
        std::string tip;
        is >> tip;
        if (tip == "bluza")
        {
            std::shared_ptr<bluza> b = std::make_shared<bluza>();
            is >> *b;
            o.adaugaHaina(std::shared_ptr<haina>(b));
        }
        else if (tip == "pantaloni")
        {
            std::shared_ptr<pantaloni> p = std::make_shared<pantaloni>();
            is >> *p;
            o.adaugaHaina(std::shared_ptr<haina>(p));
        }
        else if (tip == "incaltaminte")
        {
            std::shared_ptr<incaltaminte> i = std::make_shared<incaltaminte>();
            is >> *i;
            o.adaugaHaina(std::shared_ptr<haina>(i));
        }
    }
    o.calculeazaPretTotal();
    return is;
}
