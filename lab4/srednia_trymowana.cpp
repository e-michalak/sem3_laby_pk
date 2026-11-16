#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <numeric>
#include <stdexcept>

using namespace std;

void zapiszLog(string tekst) {
    ofstream plik("srednia.log", ios::app);
    plik << tekst << "\n";
}

int main() {
    try {
        zapiszLog("Start liczenia sredniej");
        ifstream wejscie("srednia_wejscie.csv");
        if (!wejscie) throw runtime_error("Nie znaleziono pliku wejsciowego!");

        list<double> liczby;
        double wartosc;
        while (wejscie >> wartosc) {
            liczby.push_back(wartosc);
        }

        liczby.sort();
        liczby.pop_front(); // Usuwa najmniejsz¹ wartoœæ
        liczby.pop_back();  // Usuwa najwiêksz¹ wartoœæ

        double suma = accumulate(liczby.begin(), liczby.end(), 0.0);
        double srednia = suma / liczby.size();

        ofstream wyjscie("srednia_wyjscie.csv");
        wyjscie << "Srednia_trymowana\n";
        wyjscie << srednia << "\n";

        zapiszLog("Wyliczono srednia: " + to_string(srednia));
        cout << "Srednia trymowana: " << srednia << "\n";
    } catch (exception& blad) {
        zapiszLog(string("Blad: ") + blad.what());
        cout << "Wystapil blad: " << blad.what() << "\n";
    }
    return 0;
}
