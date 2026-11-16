#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <map>
#include <stdexcept>

using namespace std;

void zapiszLog(string tekst) {
    ofstream plik("isbn.log", ios::app);
    plik << tekst << "\n";
}

int main() {
    try {
        zapiszLog("Start sprawdzania ISBN");
        ifstream wejscie("isbn_wejscie.csv");
        if (!wejscie) throw runtime_error("Nie znaleziono pliku wejsciowego!");

        map<string, string> wyniki;
        string numer;

        while (getline(wejscie, numer)) {
            if (numer.empty()) continue;

            stack<int> cyfry;
            for (char znak : numer) {
                if (isdigit(znak)) cyfry.push(znak - '0');
                else if (znak == 'X') cyfry.push(10);
            }

            if (cyfry.size() != 10) {
                wyniki[numer] = "BLEDNY";
                continue;
            }

            int suma = 0;
            for (int waga = 1; waga <= 10; ++waga) {
                suma += cyfry.top() * waga;
                cyfry.pop();
            }

            wyniki[numer] = (suma % 11 == 0) ? "POPRAWNY" : "BLEDNY";
        }

        ofstream wyjscie("isbn_wyjscie.csv");
        wyjscie << "ISBN,Status\n";
        for (auto [kod, status] : wyniki) {
            wyjscie << kod << "," << status << "\n";
        }

        zapiszLog("Zakonczono sprawdzanie ISBN");
        cout << "Gotowe!\n";
    } catch (exception& blad) {
        zapiszLog(string("Blad: ") + blad.what());
        cout << "Wystapil blad: " << blad.what() << "\n";
    }
    return 0;
}
