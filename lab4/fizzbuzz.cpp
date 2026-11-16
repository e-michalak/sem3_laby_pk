#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;

void zapiszLog(string tekst) {
    ofstream plik("fizzbuzz.log", ios::app);
    plik << tekst << "\n";
}

int main() {
    try {
        zapiszLog("Start programu FizzBuzz");
        ifstream wejscie("fizzbuzz_wejscie.csv");
        if (!wejscie) throw runtime_error("Nie znaleziono pliku wejsciowego!");

        int zakres;
        wejscie >> zakres;

        queue<int> kolejka;
        for (int i = 1; i <= zakres; ++i) kolejka.push(i);

        vector<pair<int, string>> wyniki;
        wyniki.reserve(zakres);

        while (!kolejka.empty()) {
            int liczba = kolejka.front();
            kolejka.pop();

            string napis = "";
            if (liczba % 3 == 0) napis += "Fizz";
            if (liczba % 5 == 0) napis += "Buzz";
            if (napis.empty()) napis = to_string(liczba);

            wyniki.push_back({liczba, napis});
        }

        ofstream wyjscie("fizzbuzz_wyjscie.csv");
        wyjscie << "Liczba,Wynik\n";
        for (auto [liczba, napis] : wyniki) {
            wyjscie << liczba << "," << napis << "\n";
        }

        zapiszLog("Zakonczono poprawnie");
        cout << "Gotowe!\n";
    } catch (exception& blad) {
        zapiszLog(string("Blad: ") + blad.what());
        cout << "Wystapil blad: " << blad.what() << "\n";
    }
    return 0;
}
