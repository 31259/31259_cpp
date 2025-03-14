#include <iostream>

int n1 = 0, n2 = 1, n3;

int Fibonacci(int n) {
	if (n < 2)
		return n2;
	else {
		n3 = n2;
		n2 = n1 + n2;
		n1 = n3;
		n--;
		Fibonacci(n);
	}
}

using namespace std;
int main() {
	int n;
	cout << "Podaj n-ty element fibonacci ciagu: ";
	cin >> n;
	cout << "Fibonacci " << " wynosi " << Fibonacci(n) << endl;
	return 0;
}