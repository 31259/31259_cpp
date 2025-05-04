#include <iostream> 
#include <cstdlib>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace chrono;

int licznikSwap = 0, licznikSearch = 0;

void swap(int& a, int& b) {
    licznikSwap++;
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

int binarySearch(int arr[], int left, int right, int target) {
    licznikSearch++;
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);
        else
            return binarySearch(arr, mid + 1, right, target);
    }
    return -1; 
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
    for (int y = 0; y < x; y++) {
        table[y] = rand() % roznica + pocz;
    }

    auto start = high_resolution_clock::now();
    quickSort(table, 0, x - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Czas wykonania QuickSort: " << duration.count() << " ms" << endl;

    int n = sizeof(table) / sizeof(table[0]);

    int target;
    cout << "Podaj co szukamy: ";
    cin >> target;

    auto start1 = high_resolution_clock::now();
    int result = binarySearch(table, 0, n - 1, target);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1);
    cout << "Czas wykonania wyszukiwania binarnego: " << duration1.count() << " ms" << endl;

    if (result != -1)
        cout << "Element znaleziony na indeksie " << result << endl;
    else
        cout << "Element nie znaleziony" << endl;

    cout << "Ilosc wywolania swap: " << licznikSwap << endl;
    cout << "Ilosc wywolania binarySearch: " << licznikSearch << endl;

    cout << "Czas laczny wykonania obu operacji: " << duration.count() + duration.count() << "ms" << endl;
}