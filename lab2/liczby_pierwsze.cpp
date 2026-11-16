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

    auto czy_pierwsza = [](int n) {
        auto check = [](auto self, int n, int d) -> bool {
            return (n <= 1) ? false :
                   (d * d > n) ? true :
                   (n % d == 0) ? false :
                   self(self, n, d + 1);
        };
        return check(check, n, 2);
    };

    cout << "Liczby pierwsze:\n";

    copy_if(
        istream_iterator<int>(ss), istream_iterator<int>(),
        ostream_iterator<int>(cout, "\n"),
        czy_pierwsza
    );
}