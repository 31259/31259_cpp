#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int MatrixChainDP(const vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = numeric_limits<int>::max();

            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> dims7 = { 41, 93, 95, 37, 29, 77, 12, 30 };
    cout << "--- Przyklad 1: 7 macierzy ---\n";
    cout << "Rozmiary: ";
    for (int d : dims7) cout << d << " ";
    cout << "\nMinimalna liczba mnozen: " << MatrixChainDP(dims7) << "\n\n";

    vector<int> dims15 = { 75, 71, 16, 100, 52, 71, 20, 31, 85, 50, 51, 95, 100, 94, 100, 88 };
    cout << "--- Przyklad 2: 15 macierzy ---\n";
    cout << "Rozmiary: ";
    for (int d : dims15) cout << d << " ";
    cout << "\nMinimalna liczba mnozen: " << MatrixChainDP(dims15) << "\n";

    return 0;
}
