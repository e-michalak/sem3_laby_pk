#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

void loguj(const string& m) {
    ofstream f("log_detekcja.txt", ios::app);
    f << m << "\n";
}

int main() {
    loguj("Start");
    ifstream d("dane.csv");
    ofstream w("wynik_detekcja.md");
    w << "# Detekcja\n";
    
    istream_iterator<string> it(d), koniec;
    for_each(it, koniec, [&](const string& l) {
        string k = "";
        for (auto z = l.begin(); z != l.end(); ++z) {
            if (*z == ',') {
                for (auto s = k.begin(); s != k.end(); ++s) {
                    if (isupper(*s)) w << "- " << *s << "\n";
                }
                k = "";
            } else {
                k += *z;
            }
        }
    });

    loguj("Koniec");
    return 0;
}