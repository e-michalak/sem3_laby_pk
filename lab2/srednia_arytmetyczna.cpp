#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    ifstream f("numbers_mean.csv");
    string s((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
    replace(s.begin(), s.end(), ',', ' ');

    stringstream ss(s);

    pair<double, int> res = accumulate(
        istream_iterator<double>(ss), istream_iterator<double>(),
        make_pair(0.0, 0),
        [](pair<double, int> acc, double val) {
            return make_pair(acc.first + val, acc.second + 1);
        }
    );

    double count = max(1.0, (double)res.second);
    cout << "Średnia: " << res.first / count << endl;
}
