#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 100;

class Queue {
private:
    int arr[MAX];
    int front, rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Kolejka pelna!" << endl;
            return;
        }
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Kolejka pusta!" << endl;
            return -1;
        }
        return arr[front++];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Kolejka pusta!" << endl;
            return -1;
        }
        return arr[front];
    }

    int size() {
        return isEmpty() ? 0 : rear - front + 1;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Kolejka pusta." << endl;
            return;
        }
        for (int i = rear; i >= front; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void resetQueue() {
        front = 0;
        rear = -1;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printQueue();

    cout << "Pierwszy element: " << q.peek() << endl;
    q.dequeue();
    q.printQueue();

    int n;
    cout << "Podaj liczbe elementow do dodania: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        q.enqueue(rand() % 100);
    }
    q.printQueue();

    int count = q.size();
    cout << "Liczba elementow w kolejce: " << count << endl;
    if (n == count) cout << "Zgadza sie." << endl;
    else cout << "Nie zgadza sie." << endl;

    q.resetQueue();
    q.printQueue();

    q.enqueue(5);
    q.enqueue(15);
    q.dequeue();
    q.printQueue();

    return 0;
}
