#include "Menjacnica.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>

Menjacnica::Menjacnica(const string& fajlIme) : fajlIme(fajlIme) {
    ucitajValute();
}

void Menjacnica::dodajValutu(const Valuta& valuta) {
    valute[valuta.getNaziv()] = valuta;
    sacuvajValute();
}

double Menjacnica::konvertuj(const string& izValute, const string& uValutu, double iznos) {
    if (valute.find(izValute) == valute.end() || valute.find(uValutu) == valute.end()) {
        throw invalid_argument("Nepostojeca valuta.");
    }
    double kursIzValute = valute[izValute].getKurs();
    double kursUValute = valute[uValutu].getKurs();
    double iznosUSD = iznos / kursIzValute;
    return iznosUSD * kursUValute;
}

void Menjacnica::ucitajValute() {
    ifstream fajl(fajlIme);
    if (!fajl.is_open()) {
        throw runtime_error("Ne mogu otvoriti fajl.");
    }

    string linija;
    while (getline(fajl, linija)) {
        istringstream ss(linija);
        string naziv;
        double kurs;
        if (ss >> naziv >> kurs) {
            valute[naziv] = Valuta(naziv, kurs);
        }
    }
    fajl.close();
}

void Menjacnica::sacuvajValute() {
    ofstream fajl(fajlIme, ofstream::trunc);
    if (!fajl.is_open()) {
        throw runtime_error("Ne mogu otvoriti fajl.");
    }

    for (const auto& par : valute) {
        fajl << par.second.getNaziv() << " " << par.second.getKurs() << endl;
    }
    fajl.close();
}

void Menjacnica::prikaziValute() {
    cout << "Dostupne valute i njihovi kursevi prema USD:\n";
    for (const auto& par : valute) {
        cout << par.second.getNaziv() << ": " << par.second.getKurs() << endl;
    }
}

void Menjacnica::promeniKurs(const string& nazivValute, double noviKurs) {
    if (valute.find(nazivValute) == valute.end()) {
        throw invalid_argument("Nepostojeca valuta.");
    }
    valute[nazivValute].setKurs(noviKurs);
    sacuvajValute();
}
