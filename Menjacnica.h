#define MENJACNICA_H

#include "Valuta.h"
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Menjacnica {
private:
    unordered_map<string, Valuta> valute;
    string fajlIme;

public:
    Menjacnica(const string& fajlIme);
    void dodajValutu(const Valuta& valuta);
    double konvertuj(const string& izValute, const string& uValutu, double iznos);
    void ucitajValute();
    void sacuvajValute();
    void prikaziValute();
    void promeniKurs(const string& nazivValute, double noviKurs);
};

