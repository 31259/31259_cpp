#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class GraphMatrix {
private:
    vector<vector<int>> graphMatrix;
    int verticesNumber;
    vector<string> vertexNames;

public:
    GraphMatrix(int vertices, const vector<string>& names) {
        verticesNumber = vertices;
        vertexNames = names;
        graphMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int i, int j) {
        graphMatrix[i][j] = 1;
        graphMatrix[j][i] = 1; // usun, jeœli graf ma byæ skierowany
    }

    void print() {
        cout << "  ";
        for (const auto& name : vertexNames) cout << name << " ";
        cout << "\n";
        for (int i = 0; i < verticesNumber; ++i) {
            cout << vertexNames[i] << " ";
            for (int j = 0; j < verticesNumber; ++j) {
                cout << graphMatrix[i][j] << "  ";
            }
            cout << "\n";
        }
    }
};

class GraphList {
private:
    vector<vector<int>> graphList;
    vector<string> vertexNames;

public:
    GraphList(int vertices, const vector<string>& names) {
        graphList.resize(vertices);
        vertexNames = names;
    }

    void addEdge(int u, int v) {
        graphList[u].push_back(v);
        graphList[v].push_back(u); // usun, jeœli graf ma byæ skierowany
    }

    void print() {
        for (int i = 0; i < graphList.size(); ++i) {
            cout << vertexNames[i] << ": ";
            for (int neighbor : graphList[i]) {
                cout << vertexNames[neighbor] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int numVertices;
    cout << "Podaj liczbe wierzcholkow: ";
    cin >> numVertices;

    vector<string> names(numVertices);
    cout << "Podaj nazwy wierzcholkow:\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << i << ": ";
        cin >> names[i];
    }

    cout << "Wybierz typ grafu:\n1. Macierz sasiedztwa\n2. Lista sasiedztwa\nWybór: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        GraphMatrix gm(numVertices, names);
        cout << "Podaj krawedzie w formacie <index1> <index2> (-1 -1 aby zakonczyc):\n";
        while (true) {
            int u, v;
            cin >> u >> v;
            if (u == -1 || v == -1) break;
            gm.addEdge(u, v);
        }
        cout << "\nReprezentacja grafu - macierz sasiedztwa:\n";
        gm.print();
    }
    else if (choice == 2) {
        GraphList gl(numVertices, names);
        cout << "Podaj krawedzie w formacie <index1> <index2> (-1 -1 aby zakobczyc):\n";
        while (true) {
            int u, v;
            cin >> u >> v;
            if (u == -1 || v == -1) break;
            gl.addEdge(u, v);
        }
        cout << "\nReprezentacja grafu - lista sasiedztwa:\n";
        gl.print();
    }
    else {
        cout << "Nieprawidlowy wybor.\n";
    }

    return 0;
}
