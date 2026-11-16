#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ifstream f("dane_wej.csv");
    string s((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
    replace(s.begin(), s.end(), ',', ' ');

    stringstream ss(s);

    auto fb = [](int n) {
        string f_arr[2] = {"", "Fizz"};
        string b_arr[2] = {"", "Buzz"};
        string fb_str = f_arr[n % 3 == 0] + b_arr[n % 5 == 0];
        int has_fb = (n % 3 == 0) || (n % 5 == 0);
        string opt[2] = {to_string(n), fb_str};
        return opt[has_fb] + "\n";
    };

    string out = accumulate(
        istream_iterator<int>(ss), istream_iterator<int>(),
        string(""),
        [fb](string acc, int n) { return acc + fb(n); }
    );

    cout << out;
}
