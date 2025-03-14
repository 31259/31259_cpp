#include <iostream>
using namespace std;

int silnia(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * silnia(n - 1);
	}
}

int main() {
	int n = 1;
	cout << "Podaj liczbê: ";

	do {
		if (n < 0) cout << "podaj liczbe ponownie, dodatnia: ";
		cin >> n;
	} while (n < 0);

	cout << "Silnia " << n << " wynosi: " << silnia(n) << endl;
}