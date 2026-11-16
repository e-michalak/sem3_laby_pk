#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <array>
#include <unordered_map>
#include <sstream>
#include <stdexcept>

using namespace std;

void zapiszLog(string tekst) {
    ofstream plik("ip.log", ios::app);
    plik << tekst << "\n";
}

bool sprawdzAdres(string adres) {
    queue<string> kolejka;
    stringstream strumien(adres);
    string kawalek;

    while (getline(strumien, kawalek, '.')) kolejka.push(kawalek);
    if (kolejka.size() != 4) return false;

    array<int, 4> czesci;
    for (int i = 0; i < 4; ++i) {
        int liczba = stoi(kolejka.front());
        kolejka.pop();

        if (liczba < 0 || liczba > 255) return false;
        czesci[i] = liczba;
    }
    return true;
}

int main() {
    try {
        zapiszLog("Start sprawdzania IP");
        ifstream wejscie("ip_wejscie.csv");
        if (!wejscie) throw runtime_error("Nie znaleziono pliku wejsciowego!");

        unordered_map<string, string> raport;
        string adres;

        while (getline(wejscie, adres)) {
            if (adres.empty()) continue;
            raport[adres] = sprawdzAdres(adres) ? "POPRAWNY" : "BLEDNY";
        }

        ofstream wyjscie("ip_wyjscie.csv");
        wyjscie << "Adres_IP,Status\n";
        for (auto [ip, status] : raport) {
            wyjscie << ip << "," << status << "\n";
        }

        zapiszLog("Zakonczono sprawdzanie IP");
        cout << "Gotowe!\n";
    } catch (exception& blad) {
        zapiszLog(string("Blad: ") + blad.what());
        cout << "Wystapil blad: " << blad.what() << "\n";
    }
    return 0;
}
