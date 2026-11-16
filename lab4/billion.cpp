#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

struct Dane {
    double min_temp = 1000.0;
    double max_temp = -1000.0;
    double suma = 0.0;
    long long licznik = 0;
};

int main() {
    ios_base::sync_with_stdio(false);
    ifstream plik("measurements.txt");
    if (!plik) return 1;

    map<string, Dane> stacje;
    string linia;

    while (getline(plik, linia)) {
        size_t poz = linia.find(';');
        if (poz == string::npos) continue;

        string nazwa = linia.substr(0, poz);
        double temp = stod(linia.substr(poz + 1));

        auto& d = stacje[nazwa];
        if (temp < d.min_temp) d.min_temp = temp;
        if (temp > d.max_temp) d.max_temp = temp;
        d.suma += temp;
        d.licznik++;
    }

    cout << fixed << setprecision(1);
    for (const auto& [nazwa, d] : stacje) {
        double srednia = d.suma / d.licznik;
        cout << nazwa << ": min=" << d.min_temp
             << ", max=" << d.max_temp
             << ", srednia=" << srednia << "\n";
    }

    return 0;
}
