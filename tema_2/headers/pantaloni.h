#ifndef PANTALONI_H
#define PANTALONI_H

#include "../headers/haina.h"

class pantaloni : public haina
{
    bool curea;
    std::string lungime;

public:
    pantaloni();
    pantaloni(float pret, const std::string &producator, const std::string &culoare, const std::string &marime, const std::vector<std::string> &materiale, bool curea, const std::string &lungime);
    pantaloni(const pantaloni &p);
    ~pantaloni();

    bool getCurea() const;
    std::string getLungime() const;

    void setCurea(bool _curea);
    void setLungime(std::string _lungime);

    pantaloni &operator=(const pantaloni &p);
    friend std::ostream &operator<<(std::ostream &os, const pantaloni &p);
    friend std::istream &operator>>(std::istream &is, pantaloni &p);

    void descriere() override;
};

#endif // PANTALONI_H