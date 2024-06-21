#include "Valuta.h"

Valuta::Valuta(const string& naziv, double kurs) : naziv(naziv), kurs(kurs) {}
Valuta::Valuta() {}

string Valuta::getNaziv() const {
    return naziv;
}

double Valuta::getKurs() const {
    return kurs;
}

void Valuta::setKurs(double kurs) {
    this->kurs = kurs;
}
