#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    ifstream f("dane_wej.csv");
    string s((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
    replace(s.begin(), s.end(), ',', ' ');

    stringstream ss(s);

    auto czy_poprawne = [](const string& str) {
        return str.length() == 6 && str[2] == '-' &&
               str[0] >= '0' && str[0] <= '9' &&
               str[1] >= '0' && str[1] <= '9' &&
               str[3] >= '0' && str[3] <= '9' &&
               str[4] >= '0' && str[4] <= '9' &&
               str[5] >= '0' && str[5] <= '9';
    };

    copy_if(
        istream_iterator<string>(ss), istream_iterator<string>(),
        ostream_iterator<string>(cout, "\n"),
        czy_poprawne
    );
}
