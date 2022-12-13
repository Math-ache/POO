#ifndef BLUZA_H
#define BLUZA_H

#include "../headers/haina.h"

class bluza : public haina
{
    bool gluga;
    std::string inchidere;

public:
    bluza();
    bluza(float pret, std::string producator, std::string culoare, std::string marime, std::vector<std::string> materiale, bool gluga, std::string inchidere);
    bluza(const bluza &b);
    ~bluza();

    bool getGluga() const;
    std::string getInchidere() const;

    void setGluga(bool gluga);
    void setInchidere(std::string inchidere);

    bluza &operator=(const bluza &b);
    friend std::ostream &operator<<(std::ostream &os, const bluza &b);
    friend std::istream &operator>>(std::istream &is, bluza &b);

    void descriere();
};

#endif // BLUZA_H