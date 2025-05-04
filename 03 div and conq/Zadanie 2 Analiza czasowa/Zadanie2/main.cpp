#include <iostream> 
#include <cstdlib>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void search(int arr[], int x) {
    int l;
    bool istnieje = false;
    cout << "Podaj liczbe do wyszukiwania ";
    cin >> l;

    for (int y = 0; y < x; y++) {
        if (arr[y] == l) {
            cout << "Znaleziono pod indeksem: " << y << endl;
            istnieje = true;
        }
    }
    if (istnieje == false) {
        cout << "Liczby " << l << " w tablice nie ma";
    }
}


int main() {
    int x, pocz, kon, roznica;
    cout << "Podaj rozmiar tablicy ";
    cin >> x;

    cout << "Podaj poczotek zakresa: ";
    cin >> pocz;

    cout << "Podaj koniec zakresa: ";
    cin >> kon;

    roznica = kon - pocz;

    int* table = new int[x];
    int* table1 = new int[x];
    for (int y = 0; y < x; y++) {
        table1[y] = table[y] = rand() % roznica + pocz;
    }

    auto start = high_resolution_clock::now();
    quickSort(table, 0, x - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Czas wykonania QuickSort: " << duration.count() << " ms" << endl;

    auto start2 = high_resolution_clock::now();
    sort(table1, table1 + x);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2);
    cout << "Czas sort() STL: " << duration2.count() << " ms" << endl;
    return 0;
}