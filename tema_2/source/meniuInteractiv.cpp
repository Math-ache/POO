#include "../headers/meniuInteractiv.h"
#include "../headers/exceptii.h"

int meniuInteractiv::numarOutfituri = 0;
std::vector<outfit> meniuInteractiv::outfituri = {};

void meniuInteractiv::introducereOutfit(int n)
{
    if (n == -1)
        std::cout << "\nIntroduceti numarul de haine din outfit: ";
    else
        std::cout << "\nIntroduceti numarul de haine din outfitul " << n << ": ";

    try
    {
        int nrHaine;
        std::cin >> nrHaine;
        std::vector<std::shared_ptr<haina>> haine;
        for (int i = 0; i < nrHaine; i++)
        {
            try
            {
                std::cout << "Introduceti tipul hainei (bluza, pantaloni, incaltaminte): ";
                std::string tipHaina;
                std::cin >> tipHaina;
                if (tipHaina == "bluza")
                {
                    auto h = std::make_shared<bluza>();
                    std::cin >> *h;
                    haine.push_back(h);
                }
                else if (tipHaina == "pantaloni")
                {
                    auto h = std::make_shared<pantaloni>();
                    std::cin >> *h;
                    haine.push_back(h);
                }
                else if (tipHaina == "incaltaminte")
                {
                    auto h = std::make_shared<incaltaminte>();
                    std::cin >> *h;
                    haine.push_back(h);
                }
                else
                {
                    throw hainaInvalida();
                }
            }
            catch (const hainaInvalida &e)
            {
                std::cout << e.what() << '\n';
                i--;
            }
        }
        outfit o(haine);
        o.calculeazaPretTotal();
        outfituri.push_back(o);
        numarOutfituri++;
    }
    catch (const inputInvalid &e)
    {
        std::cout << e.what() << '\n';
        introducereOutfit(n);
    }
}

void meniuInteractiv::afisareOutfit()
{
    std::cout << "Introduceti numarul outfitului pe care doriti sa il afisati (de la 1 la " << numarOutfituri << "):";
    int nrOutfit;
    std::cin >> nrOutfit;

    if (nrOutfit > numarOutfituri || nrOutfit < 1)
    {
        std::cout << "Numarul introdus nu este valid!\n";
        return;
    }

    std::cout << outfituri[nrOutfit - 1] << '\n';
}

void meniuInteractiv::afisarePretOutfit()
{
    std::cout << "Introduceti numarul outfitului al carui pret doriti sa il afisati (de la 1 la " << numarOutfituri << "):";
    int nrOutfit;
    std::cin >> nrOutfit;

    if (nrOutfit > numarOutfituri || nrOutfit < 1)
    {
        std::cout << "Numarul introdus nu este valid!\n";
        return;
    }

    std::cout << "\nPretul outfitului este: " << outfituri[nrOutfit - 1].getPretTotal() << '\n';
}

void meniuInteractiv::afisareOutfituri()
{
    std::cout << "Introduceti numarul de outfituri pe care doriti sa le afisati (de la 1 la " << numarOutfituri << "):";
    int nrOutfituri;
    std::cin >> nrOutfituri;

    if (nrOutfituri > numarOutfituri || nrOutfituri < 1)
    {
        std::cout << "Numarul introdus nu este valid!\n";
        return;
    }

    for (int i = 0; i < nrOutfituri; i++)
    {
        std::cout << outfituri[i] << '\n';
    }
}

void meniuInteractiv::introducereOutfituri()
{
    std::cout << "\nIntroduceti numarul de outfituri pe care doriti sa le adaugati:";
    int nrOutfituri;
    std::cin >> nrOutfituri;

    for (int i = 0; i < nrOutfituri; i++)
        introducereOutfit(i + 1);
}

void meniuInteractiv::afisarePreturi()
{
    std::cout << "\nIntroduceti numarul de outfituri al caror pret doriti sa il afisati (de la 1 la " << numarOutfituri << "):";
    int nrOutfituri;
    std::cin >> nrOutfituri;

    if (nrOutfituri > numarOutfituri || nrOutfituri < 1)
    {
        std::cout << "Numarul introdus nu este valid!\n";
        return;
    }

    for (int i = 0; i < nrOutfituri; i++)
    {
        std::cout << "Pretul outfitului " << i + 1 << " este: " << outfituri[i].getPretTotal() << '\n';
    }
}

void meniuInteractiv::adaugareBluzaLaOutfit()
{
    std::cout << "Introduceti numarul outfitului la care doriti sa adaugati o bluza (de la 1 la " << numarOutfituri << "):";
    int nrOutfit;
    std::cin >> nrOutfit;

    if (nrOutfit > numarOutfituri || nrOutfit < 1)
    {
        std::cout << "Numarul introdus nu este valid!\n";
        return;
    }

    auto b = std::make_shared<bluza>();
    std::cin >> *b;
    outfituri[nrOutfit - 1].adaugaHaina(b);
    outfituri[nrOutfit - 1].calculeazaPretTotal();
}

void meniuInteractiv::adaugarePantaloniLaOutfit()
{
    std::cout << "Introduceti numarul outfitului la care doriti sa adaugati o pereche de pantaloni (de la 1 la " << numarOutfituri << "):";
    int nrOutfit;
    std::cin >> nrOutfit;

    if (nrOutfit > numarOutfituri || nrOutfit < 1)
    {
        std::cout << "Numarul introdus nu este valid!\n";
        return;
    }

    auto p = std::make_shared<pantaloni>();
    std::cin >> *p;
    outfituri[nrOutfit - 1].adaugaHaina(p);
    outfituri[nrOutfit - 1].calculeazaPretTotal();
}

void meniuInteractiv::adaugareIncaltaminteLaOutfit()
{
    std::cout << "Introduceti numarul outfitului la care doriti sa adaugati o pereche de incaltaminte (de la 1 la " << numarOutfituri << "):";
    int nrOutfit;
    std::cin >> nrOutfit;

    if (nrOutfit > numarOutfituri || nrOutfit < 1)
    {
        std::cout << "Numarul introdus nu este valid!\n";
        return;
    }

    auto i = std::make_shared<incaltaminte>();
    std::cin >> *i;
    outfituri[nrOutfit - 1].adaugaHaina(i);
    outfituri[nrOutfit - 1].calculeazaPretTotal();
}

void meniuInteractiv::descriereOutfit()
{
    std::cout << "\nIntroduceti numarul outfitului a carui descriere doriti sa o afisati (de la 1 la " << numarOutfituri << "):";
    int nrOutfit;
    std::cin >> nrOutfit;

    if (nrOutfit > numarOutfituri || nrOutfit < 1)
    {
        std::cout << "Numarul introdus nu este valid!\n";
        return;
    }

    for (size_t i = 0; i < outfituri[nrOutfit - 1].getHaine().size(); i++)
    {

        outfituri[nrOutfit - 1].getHaine()[i]->descriere();
    }
}

void meniuInteractiv::meniuPrincipal()
{
    int optiune = 0;
    do
    {
        std::cout << "\n1. Introducere outfit\n";
        std::cout << "2. Afisare outfit\n";
        std::cout << "3. Afisare pret outfit\n";
        std::cout << "4. Introducere outfituri\n";
        std::cout << "5. Afisare outfituri\n";
        std::cout << "6. Afisare preturi\n";
        std::cout << "7. Adaugare bluza la outfit\n";
        std::cout << "8. Adaugare pantaloni la outfit\n";
        std::cout << "9. Adaugare incaltaminte la outfit\n";
        std::cout << "10. Descrierea unui outfit\n";
        std::cout << "0. Iesire\n\n";

        std::cout << "Introduceti optiunea dorita: ";

        std::cin >> optiune;

        switch (optiune)
        {
        case 1:
            meniuInteractiv::introducereOutfit();
            break;
        case 2:
            meniuInteractiv::afisareOutfit();
            break;
        case 3:
            meniuInteractiv::afisarePretOutfit();
            break;
        case 4:
            meniuInteractiv::introducereOutfituri();
            break;
        case 5:
            meniuInteractiv::afisareOutfituri();
            break;
        case 6:
            meniuInteractiv::afisarePreturi();
            break;
        case 7:
            meniuInteractiv::adaugareBluzaLaOutfit();
            break;
        case 8:
            meniuInteractiv::adaugarePantaloniLaOutfit();
            break;
        case 9:
            meniuInteractiv::adaugareIncaltaminteLaOutfit();
            break;
        case 10:
            meniuInteractiv::descriereOutfit();
            break;
        case 0:
            break;

        default:
            std::cout << "Optiunea introdusa nu este valida!\n";
            break;
        }
    } while (optiune != 0);
}
