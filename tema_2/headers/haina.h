#ifndef HAINA_H
#define HAINA_H

#include <iostream>
#include <string>
#include <vector>

class haina
{
private:
    float pret;
    std::string producator;
    std::string culoare;
    std::string marime;
    std::vector<std::string> materiale;

public:
    haina();
    haina(float pret, const std::string &producator, const std::string &culoare, const std::string &marime, const std::vector<std::string> &materiale);
    haina(const haina &h);
    virtual ~haina();

    float getPret() const;
    std::string getProducator() const;
    std::string getCuloare() const;
    std::string getMarime() const;
    std::vector<std::string> getMateriale() const;

    void setPret(float _pret);
    void setProducator(const std::string &_producator);
    void setCuloare(const std::string &_culoare);
    void setMarime(const std::string &_marime);
    void setMateriale(const std::vector<std::string> &_materiale);

    // rescriere constructor copiere
    haina &operator=(const haina &h);
    friend std::ostream &operator<<(std::ostream &os, const haina &h);
    friend std::istream &operator>>(std::istream &is, haina &h);

    virtual void descriere() = 0;
};

#endif // HAINA_H