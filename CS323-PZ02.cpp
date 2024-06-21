#include <iostream>
#include "Menjacnica.h"

using namespace std;

void prikaziMeni() {
    cout << "1. Dodaj valutu\n";
    cout << "2. Konvertuj valutu\n";
    cout << "3. Prikazi sve valute\n";
    cout << "4. Promeni kurs valute\n";
    cout << "5. Izadji\n";
}

int main() {
    Menjacnica menjacnica("valute.txt");
    int izbor;
    do {
        prikaziMeni();
        cout << "Izaberite opciju: ";
        cin >> izbor;

        if (izbor == 1) {
            string naziv;
            double kurs;
            cout << "Unesite naziv valute: ";
            cin >> naziv;
            cout << "Unesite kurs valute prema USD: ";
            cin >> kurs;
            menjacnica.dodajValutu(Valuta(naziv, kurs));
        }
        else if (izbor == 2) {
            string izValute, uValutu;
            double iznos;
            cout << "Unesite iznos: ";
            cin >> iznos;
            cout << "Unesite naziv valute iz koje konvertujete: ";
            cin >> izValute;
            cout << "Unesite naziv valute u koju konvertujete: ";
            cin >> uValutu;
            try {
                double rezultat = menjacnica.konvertuj(izValute, uValutu, iznos);
                cout << "Rezultat: " << rezultat << " " << uValutu << endl;
            }
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
        }
        else if (izbor == 3) {
            menjacnica.prikaziValute();
        }
        else if (izbor == 4) {
            menjacnica.prikaziValute();
            string naziv;
            cout << "Unesite naziv valute kojoj zelite promeniti kurs: ";
            cin >> naziv;
            try {
                double trenutniKurs = menjacnica.konvertuj(naziv, "USD", 1);
                cout << "Trenutni kurs valute " << naziv << " prema USD: " << trenutniKurs << endl;
                double noviKurs;
                cout << "Unesite novi kurs: ";
                cin >> noviKurs;
                menjacnica.promeniKurs(naziv, noviKurs);
                cout << "Kurs valute " << naziv << " je promenjen na " << noviKurs << endl;
            }
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
        }
    } while (izbor != 5);

    return 0;
}
