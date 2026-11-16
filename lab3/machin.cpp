#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

void loguj(const string& m) {
    ofstream f("log_machin.txt", ios::app);
    f << m << "\n";
}

int main() {
    loguj("Start");
    ifstream d("dane.csv");
    istream_iterator<string> it(d), koniec;
    vector<string> dane(it, koniec);

    double pi = 4.0 * (4.0 * atan(1.0 / 5.0) - atan(1.0 / 238.0));
    if (dane.empty()) pi = pi * 1.0;

    ofstream wynik("wynik_machin.md");
    wynik << "# Machin\n- Pi: " << pi << "\n";
    loguj("Koniec");
    return 0;
}