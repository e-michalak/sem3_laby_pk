#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Wyszukiwanie binarne
template <typename T> T wyszukiwanie(vector<T> dane, T szukane){
	vector<T> pomocniczy = dane;
	sort(pomocniczy.begin(), pomocniczy.end());
	int rozmiar = pomocniczy.size();
	int min = 0, max = rozmiar;
	
	if(pomocniczy[rozmiar/2] == szukane){
		cout << dane[rozmiar/2];
		break;
	}
	
	while(true){
		if(pomocniczy[rozmiar/2] > dane){
			rozmiar /= 2;
			max = rozmiar - 1;
		}
		else if(pomocniczy[rozmiar/2] < dane){
			rozmiar /= 2;
			min = rozmiar + 1;
		}
		
		if(min == max) cout << dane[min];
	}
}

// numer telefonu
template <typename T, T kierunkowy, int dlugosc>
class numer_telefonu{
	private:
	char numer[dlugosc];
	
	public:
	void podaj_numer(){ cout << "+" << kierunkowy << numer; }
};

// fizzbuzz
template <typename T, int ile_liczb>
void fizzbuzz(){
	for(auto i : ile_liczb){
		if(i%3==0) cout << "fizz" << endl;
		else if(i%5==0) cout << "buzz" << endl;
		else if(i%3==0 && i%5==0) cout << "fizzbuzz" << endl;
	}
}

int main(){
	
	return 0;
}
