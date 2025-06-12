#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string value;
    vector<Node*> children;

    Node(const string& val) : value(val) {}
};

void inOrder(Node* node) {
    if (!node) return;
    int n = node->children.size();

    if (n > 0) inOrder(node->children[0]);

    cout << node->value << " ";

    for (int i = 1; i < n; ++i) {
        inOrder(node->children[i]);
    }
}

void preOrder(Node* node) {
    if (!node) return;

    cout << node->value << " ";

    for (Node* child : node->children) {
        preOrder(child);
    }
}

int main() {
    Node* root = new Node("CEO");
    Node* cto = new Node("CTO");
    Node* cfo = new Node("CFO");
    Node* coo = new Node("COO");
    Node* dev1 = new Node("Dev1");
    Node* dev2 = new Node("Dev2");

    cto->children.push_back(dev1);
    cto->children.push_back(dev2);

    root->children.push_back(cto);
    root->children.push_back(cfo);
    root->children.push_back(coo);

    cout << "Pre-order traversal:\n";
    preOrder(root);

    cout << "\n\nIn-order traversal:\n";
    inOrder(root);

    return 0;
}


