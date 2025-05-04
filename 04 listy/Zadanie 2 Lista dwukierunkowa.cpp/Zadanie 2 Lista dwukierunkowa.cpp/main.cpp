#include <iostream>
#include <cstdlib>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

void pushFront(DNode*& head, int value) {
    DNode* newNode = new DNode{ value, nullptr, head };
    if (head) head->prev = newNode;
    head = newNode;
}

void popBack(DNode*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    DNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
}

void printList(DNode* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    DNode* head = nullptr;

    pushFront(head, 10);
    pushFront(head, 20);
    printList(head);

    popBack(head);
    printList(head);

    int n;
    cout << "Podaj liczbe wezlow: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        pushFront(head, rand() % 100);
    }
    printList(head);

    return 0;
}
