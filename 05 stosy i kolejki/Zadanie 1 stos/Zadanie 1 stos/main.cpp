#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 100;

class Stack {
private:
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1; 
    }
    bool isFull() { 
        return top == MAX - 1; 
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stos pelny!" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stos pusty!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stos pusty!" << endl;
            return -1;
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stos pusty." << endl;
            return;
        }
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void resetStack() {
        top = -1;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.printStack();

    cout << "Element z wierzchu: " << s.peek() << endl;
    s.pop();
    s.printStack();

    int n;
    cout << "Podaj liczbe elementow do dodania: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        s.push(rand() % 100);
    }
    s.printStack();

    int count = s.size();
    cout << "Liczba elementow na stosie: " << count << endl;
    if (n == count) cout << "Zgadza sie." << endl;
    else cout << "Nie zgadza sie." << endl;

    s.resetStack();
    s.printStack();

    s.push(5);
    s.push(15);
    s.pop();
    s.printStack();

    return 0;
}
