#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int value;
    int weight;
    string name;

    double valuePerKg() const {
        return (double)value / weight;
    }
};

int main() {
    vector<Item> items = {
        {60, 10, "Przedmiot 1"},
        {100, 20, "Przedmiot 2"},
        {120, 30, "Przedmiot 3"}
    };

    int capacity = 50;
    double totalWeight = 0;
    double totalValue = 0;

    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.valuePerKg() > b.valuePerKg();
        });

    cout << "--- Przedmioty w kolejno�ci zach�annej ---\n";
    for (auto& item : items) {
        cout << item.name << ": "
            << item.weight << " kg, "
            << item.value << " zl, "
            << fixed << setprecision(2) << item.valuePerKg() << " zl/kg\n";
    }

    cout << "\n--- Przedmioty wybrane do plecaka ---\n";

    for (auto& item : items) {
        if (capacity == 0) break;

        if (item.weight <= capacity) {
            cout << item.name << " (100%)\n";
            totalWeight += item.weight;
            totalValue += item.value;
            capacity -= item.weight;
        }
        else {
            double fraction = (double)capacity / item.weight;
            cout << item.name << " (" << fixed << setprecision(2) << fraction * 100 << "%)\n";
            totalWeight += capacity;
            totalValue += item.value * fraction;
            capacity = 0;
        }
    }

    cout << "\n--- Wynik ---\n";
    cout << "Laczna waga: " << totalWeight << " kg\n";
    cout << "Laczna wartosc: " << fixed << setprecision(2) << totalValue << " zl\n";

    return 0;
}
