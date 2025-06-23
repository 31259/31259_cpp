#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Przedmiot {
    int waga;
    int wartosc;
};

void solveKnapsack(const vector<Przedmiot>& przedmioty, int capacity) {
    int n = przedmioty.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            dp[i][w] = dp[i - 1][w];
            if (przedmioty[i - 1].waga <= w) {
                dp[i][w] = max(dp[i][w],
                    przedmioty[i - 1].wartosc + dp[i - 1][w - przedmioty[i - 1].waga]);
            }
        }
    }

    cout << "--- Rozwiazanie dynamiczne ---\n";
    cout << "Maksymalna wartosc: " << dp[n][capacity] << " zl\n";

    int w = capacity;
    int totalWeight = 0;
    cout << "Wybrane przedmioty:\n";
    for (int i = n; i > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "  Przedmiot " << i
                << ": " << przedmioty[i - 1].waga << " kg, "
                << przedmioty[i - 1].wartosc << " zl\n";
            totalWeight += przedmioty[i - 1].waga;
            w -= przedmioty[i - 1].waga;
        }
    }

    cout << "Laczna waga: " << totalWeight << " kg\n";
}

int main() {
    vector<Przedmiot> przedmioty = {
        {10, 60}, {20, 100}, {30, 120}, {5, 25}, {36, 170}, {8, 45}, {3, 10}, {11, 23}, {21, 110}, {12, 77}
    };
    int capacity = 50;

    solveKnapsack(przedmioty, capacity);
    return 0;
}
