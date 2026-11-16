#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <utility>

using namespace std;

struct Data {
    double x, p;
};

istream& operator>>(istream& is, Data& d) {
    char comma;
    return is >> d.x >> comma >> d.p;
}

int main() {
    ifstream f("dane_wej.csv");
    string s((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
    replace(s.begin(), s.end(), ',', ' ');

    stringstream ss(s);

    pair<double, double> res = accumulate(
        istream_iterator<Data>(ss), istream_iterator<Data>(),
        make_pair(0.0, 0.0),
        [](pair<double, double> acc, Data d) {
            return make_pair(acc.first + (d.x * d.p), acc.second + d.p);
        }
    );

    double total_p = max(1.0, res.second);
    cout << "Wartość oczekiwana: " << res.first / total_p << endl;
}