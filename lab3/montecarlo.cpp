#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;

void loguj(const string& m) {
    ofstream f("log_monte_carlo.txt", ios::app);
    f << m << "\n";
}

int main() {
    loguj("Start");
    ifstream d("dane.csv");
    istream_iterator<string> it(d), koniec;
    vector<string> dane(it, koniec);

    int n = 1000;
    int wew = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);
    
    for (int i = 0; i < n; ++i) {
        double x = dist(gen);
        double y = dist(gen);
        if (x * x + y * y <= 1.0 && !dane.empty()) wew++;
    }
    
    double pi = 4.0 * wew / n;
    ofstream wynik("wynik_monte_carlo.md");
    wynik << "# Monte Carlo\n- Pi: " << pi << "\n";
    loguj("Koniec");
    return 0;
}