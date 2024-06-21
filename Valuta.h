#define VALUTA_H

#include <string>

using namespace std;

class Valuta {
private:
    string naziv;
    double kurs;

public:
    Valuta();
    Valuta(const string& naziv, double kurs);
    string getNaziv() const;
    double getKurs() const;
    void setKurs(double kurs);
};

