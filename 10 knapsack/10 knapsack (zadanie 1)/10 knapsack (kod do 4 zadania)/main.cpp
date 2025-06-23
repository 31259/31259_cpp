#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

struct Item {
    int value;
    int weight;
    string name;
};

int main() {
    vector<Item> items = {
        {60, 10, "Przedmiot 1"},
        {100, 20, "Przedmiot 2"},
        {120, 30, "Przedmiot 3"}
    };

    int maxWeight = 50;
    int n = items.size();
    int maxVal = 0;
    vector<int> bestConfig;

    cout << "--- Wszystkie konfiguracje ---\n\n";

    for (int mask = 0; mask < (1 << n); ++mask) {
        int totalWeight = 0;
        int totalValue = 0;
        vector<int> selected;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                totalWeight += items[i].weight;
                totalValue += items[i].value;
                selected.push_back(i);
            }
        }

        cout << "Konfiguracja: ";
        if (selected.empty()) {
            cout << "(brak)";
        }
        else {
            for (int i : selected)
                cout << items[i].name << " ";
        }
        cout << "| Waga: " << totalWeight << " kg"
            << ", Wartosc: " << totalValue << " zl";

        if (totalWeight <= maxWeight && totalValue > maxVal) {
            maxVal = totalValue;
            bestConfig = selected;
        }

        cout << "\n";
    }

    cout << "\n--- Rozwiazanie optymalne ---\n";
    cout << "Wartosc maksymalna: " << maxVal << " zl\n";
    int bestWeight = 0;
    cout << "Przedmioty: ";
    for (int i : bestConfig) {
        cout << items[i].name << " ";
        bestWeight += items[i].weight;
    }
    cout << "| Waga: " << bestWeight << " kg\n";

    return 0;
}
