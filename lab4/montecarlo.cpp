#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <list>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

void zapiszLog(string tekst) {
    ofstream plik("pi.log", ios::app);
    plik << tekst << "\n";
}

int main() {
    try {
        zapiszLog("Start obliczen PI");
        ifstream wejscie("pi_wejscie.csv");
        if (!wejscie) throw runtime_error("Nie znaleziono pliku wejsciowego!");

        int liczbaProb;
        wejscie >> liczbaProb;

        srand(time(nullptr));
        list<array<double, 2>> punkty;
        int trafienia = 0;

        for (int i = 0; i < liczbaProb; ++i) {
            double x = (double)rand() / RAND_MAX;
            double y = (double)rand() / RAND_MAX;
            punkty.push_back({x, y});

            if (x * x + y * y <= 1.0) trafienia++;
        }

        double wynikPi = 4.0 * trafienia / liczbaProb;

        ofstream wyjscie("pi_wyjscie.csv");
        wyjscie << "Proby,Liczba_PI\n";
        wyjscie << liczbaProb << "," << wynikPi << "\n";

        zapiszLog("Wyliczono PI: " + to_string(wynikPi));
        cout << "Liczba PI wynosi okolo: " << wynikPi << "\n";
    } catch (exception& blad) {
        zapiszLog(string("Blad: ") + blad.what());
        cout << "Wystapil blad: " << blad.what() << "\n";
    }
    return 0;
}
