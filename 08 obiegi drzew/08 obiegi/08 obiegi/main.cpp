#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct Node {
    string data;
    vector<shared_ptr<Node>> children;

    Node(const string& d) : data(d) {}
};

void addChild(shared_ptr<Node> parent, shared_ptr<Node> child) {
    parent->children.push_back(child);
}

void printTree(const shared_ptr<Node>& node, int depth = 0) {
    for (int i = 0; i < depth; ++i) {
        cout << " ";
    }
    cout << node->data << "\n";
    for (const shared_ptr<Node>& child : node->children) {
        printTree(child, depth + 1);
    }
}

void preorder(const shared_ptr<Node>& node) {
    if (!node) return;
    cout << node->data << endl;
    for (const auto& child : node->children) {
        preorder(child);
    }
}


void inorder(const shared_ptr<Node>& node) {
    if (!node) return;
    size_t n = node->children.size();
    for (size_t i = 0; i < n / 2; ++i) {
        inorder(node->children[i]);
    }
    cout << node->data << endl;
    for (size_t i = n / 2; i < n; ++i) {
        inorder(node->children[i]);
    }
}


int main() {
    shared_ptr<Node> root1 = make_shared<Node>("Prezes Sadu Rejonowego");
    shared_ptr<Node> root2 = make_shared<Node>("Dyrektor Sadu Okregowego");
    shared_ptr<Node> child1 = make_shared<Node>("I Zespol Kuratorskiej Sluzby Sadowej");
    shared_ptr<Node> child2 = make_shared<Node>("Wydzialy");
    shared_ptr<Node> child3 = make_shared<Node>("Samodzielna Sekcja Administracyjna");

    shared_ptr<Node> child4 = make_shared<Node>("I Wydzial Cywilny");
    shared_ptr<Node> child5 = make_shared<Node>("II Wydzial Karny");
    shared_ptr<Node> child6 = make_shared<Node>("III Wydzial Rodzinny i Nieletnich");
    shared_ptr<Node> child7 = make_shared<Node>("IV Wydzial Ksiag Wieczystych");

    addChild(root1, child3);
    addChild(root2, child3);

    addChild(root1, child1);
    addChild(root1, child2);

    addChild(child2, child4);
    addChild(child2, child5);
    addChild(child2, child6);
    addChild(child2, child7);

    cout << "--- Struktura drzewa ---" << endl;
    printTree(root1);
    cout << endl;

    cout << "--- Obieg preorder (PLR) ---" << endl;
    preorder(root1);
    cout << endl << endl;

    cout << "--- Obieg inorder (LPR) ---" << endl;
    inorder(root1);
    cout << endl;

    return 0;
}
