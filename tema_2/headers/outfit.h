#ifndef OUTFIT_H
#define OUTFIT_H

#include "bluza.h"
#include "pantaloni.h"
#include "incaltaminte.h"
#include <memory>

class outfit
{
    std::vector<std::shared_ptr<haina>> haine;
    float pretTotal = 0;

public:
    outfit();
    outfit(std::vector<std::shared_ptr<haina>> haine = {}, float pretTotal = 0);
    outfit(const outfit &o);
    ~outfit();

    std::vector<std::shared_ptr<haina>> getHaine() const;
    float getPretTotal() const;

    void setHaine(std::vector<std::shared_ptr<haina>> haine);

    void adaugaHaina(std::shared_ptr<haina> h);
    void calculeazaPretTotal();

    outfit &operator=(const outfit &o);
    friend std::ostream &operator<<(std::ostream &os, const outfit &o);
    friend std::istream &operator>>(std::istream &is, outfit &o);
};

#endif // OUTFIT_H