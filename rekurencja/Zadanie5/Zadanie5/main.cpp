#include <iostream>
#include <vector>

using namespace std;

void factorizacja(int n, vector<int>& factors) {
    if (n == 1) 
    {
        return;
    }

    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            cout << n << " / " << i << " = " << n / i << endl;
            factorizacja(n / i, factors);
            return;
        }
    }
}

int main() {
    int n;
    cout << "Podaj liczbe: ";
    cin >> n;
    vector<int> factors;

    factorizacja(n, factors);

    cout << "Czynniki pierwsze: ";
    for (int f : factors) cout << f << " ";
    cout << endl;

    return 0;
}