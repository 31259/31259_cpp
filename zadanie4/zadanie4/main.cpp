#include <iostream>

int licznik = 0;
int liczbaWystapien(int n, int cyfra) {
	if (n == 0)
		return licznik;
	else {
		if (cyfra == n % 10) licznik++;
		n /= 10;
		liczbaWystapien(n, cyfra);
	}
}

using namespace std;
int main() {
	int n, i;
	cout << "Podaj liczbe: ";
	cin >> n;
	cout << "Podaj cyfre jaka szukamy: ";
	cin >> i;
	cout << "Cyfra " << i << " wystapila "<< liczbaWystapien(n, i) <<" razy w liczbie "<< n <<endl;
	return 0;
}