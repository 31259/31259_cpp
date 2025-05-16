#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	string data;
	vector<shared_ptr<Node>> children;

	Node(const string& d) : data(d) {}

};

void addChild(shared_ptr<Node> parent, shared_ptr<Node> child){
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

	printTree(root1);
	printTree(root2);

}