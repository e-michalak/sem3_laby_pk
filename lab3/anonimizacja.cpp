#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

void loguj(const string& m) {
    ofstream f("log_anonimizacja.txt", ios::app);
    f << m << "\n";
}

int main() {
    loguj("Start");
    ifstream d("dane.csv");
    ofstream w("wynik_anonimizacja.md");
    w << "# Anonimizacja\n";
    
    istream_iterator<string> it(d), koniec;
    for_each(it, koniec, [&](const string& l) {
        w << "- ";
        for (auto z = l.begin(); z != l.end(); ++z) {
            char znak = *z;
            if (znak != ',' && distance(l.begin(), z) % 2 == 0) znak = '*';
            w << znak;
        }
        w << "\n";
    });

    loguj("Koniec");
    return 0;
}