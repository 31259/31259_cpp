#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

void addNode(CNode*& head, int value) {
    CNode* newNode = new CNode{ value, nullptr };
    if (!head) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    CNode* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void removeNode(CNode*& head, int value) {
    if (!head) return;
    CNode* curr = head;
    CNode* prev = nullptr;
    do {
        if (curr->data == value) {
            if (prev) {
                prev->next = curr->next;
                if (curr == head) head = curr->next;
                delete curr;
            }
            else {
                if (curr->next == head) {
                    delete head;
                    head = nullptr;
                }
                else {
                    CNode* tail = head;
                    while (tail->next != head) tail = tail->next;
                    tail->next = head->next;
                    delete head;
                    head = tail->next;
                }
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
}

void printCList(CNode* head) {
    if (!head) {
        cout << "Lista jest pusta." << endl;
        return;
    }
    CNode* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(powrot do poczatku)" << endl;
}

int main() {
    CNode* head = nullptr;


    addNode(head, 10);
    addNode(head, 20);
    addNode(head, 30);
    printCList(head);

    removeNode(head, 20);
    printCList(head);


    int arraySize, listSize;
    cout << "Podaj rozmiar tablicy do testu: ";
    cin >> arraySize;
    cout << "Podaj rozmiar listy do testu: ";
    cin >> listSize;

    try {
        int* bigArray = new int[arraySize];
        cout << "Utworzono duza tablice." << endl;
        delete[] bigArray;
    }
    catch (bad_alloc&) {
        cout << "Nie udalo sie utworzyc duzej tablicy." << endl;
    }

    CNode* bigList = nullptr;
    try {
        for (int i = 0; i < listSize; ++i) {
            addNode(bigList, i);
        }
        cout << "Utworzono duza liste." << endl;
    }
    catch (bad_alloc&) {
        cout << "Nie udalo sie utworzyc duzej listy." << endl;
    }

    return 0;
}
