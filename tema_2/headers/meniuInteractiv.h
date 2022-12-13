#ifndef MENIUINTERACTIV_H
#define MENIUINTERACTIV_H

#include "outfit.h"

class meniuInteractiv
{
    static int numarOutfituri;
    static std::vector<outfit> outfituri;

public:
    static void introducereOutfit(int n = -1);
    static void afisareOutfit();
    static void afisarePretOutfit();
    static void introducereOutfituri();
    static void afisareOutfituri();
    static void afisarePreturi();
    static void adaugareBluzaLaOutfit();
    static void adaugarePantaloniLaOutfit();
    static void adaugareIncaltaminteLaOutfit();
    static void descriereOutfit();

    static void meniuPrincipal();
};

#endif // MENIUINTERACTIV_H