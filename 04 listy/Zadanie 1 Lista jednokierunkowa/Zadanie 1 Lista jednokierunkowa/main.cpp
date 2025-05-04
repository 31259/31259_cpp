#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void pushFront(Node*& head, int value) {
    Node* newNode = new Node{ value, head };
    head = newNode;
}

void pushBack(Node*& head, int value) {
    Node* newNode = new Node{ value, nullptr };
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void popFront(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void popBack(Node*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int countNodes(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* findNode(Node* head, int value) {
    while (head) {
        if (head->data == value) return head;
        head = head->next;
    }
    return nullptr;
}

void clearList(Node*& head) {
    while (head) {
        popFront(head);
    }
}

int main() {
    Node* head = nullptr;

    pushFront(head, 10);
    pushFront(head, 20);
    pushBack(head, 5);
    printList(head);

    popFront(head);
    printList(head);

    popBack(head);
    printList(head);

    clearList(head);
    int n;
    cout << "Podaj liczbe wezlow: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        pushBack(head, rand() % 100);
    }
    printList(head);

    int liczba = countNodes(head);
    cout << "Liczba wezlow: " << liczba << endl;
    if (n == liczba) cout << "Zgadza sie." << endl;
    else cout << "Nie zgadza sie." << endl;

    int value;
    cout << "Podaj wartosc do znalezienia: ";
    cin >> value;
    Node* found = findNode(head, value);
    if (found) cout << "Znaleziono wezel z wartoscia: " << found->data << endl;
    else cout << "Nie znaleziono wezla." << endl;

    clearList(head);

    return 0;
}