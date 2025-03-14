#include <iostream>

int suma = 0, i=0;
int sumaCyfr(int n) {
	if (n == 0)
		return suma;
	else {
		suma += n % 10;
		n /= 10;
		sumaCyfr(n);
	}
}

using namespace std;
int main() {
	int n;
	cout << "Podaj liczbe: ";
	cin >> n;
	cout << "Suma liczby "<<n<<" wybosi "<< sumaCyfr(n) << endl;
	return 0;
}