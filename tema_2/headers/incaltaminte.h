#ifndef INCALTAMINTE_H
#define INCALTAMINTE_H

#include "../headers/haina.h"

class incaltaminte : public haina
{
    float grosimeTalpa;
    std::string model;

public:
    incaltaminte();
    incaltaminte(float pret, const std::string &producator, const std::string &culoare, const std::string &marime, const std::vector<std::string> &materiale, float grosimeTalpa, const std::string &model);
    incaltaminte(const incaltaminte &i);
    ~incaltaminte();

    float getGrosimeTalpa() const;
    std::string getModel() const;

    void setGrosimeTalpa(float _grosimeTalpa);
    void setModel(std::string _model);

    incaltaminte &operator=(const incaltaminte &i);
    friend std::ostream &operator<<(std::ostream &os, const incaltaminte &i);
    friend std::istream &operator>>(std::istream &is, incaltaminte &i);

    void descriere() override;
};

#endif // INCALTAMINTE_H