#include <iostream>
using namespace std;

class Graph {
private:
    int numVertices;
    int adjMatrix[10][10];

public:
    Graph(int vertices) {
        numVertices = vertices;
        for (int i = 0; i < numVertices; i++)
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = 0;
    }

    void addEdge(int i, int j) {
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1; // Undirected graph
    }

    void printMatrix() {
        cout << "\n=== Adjacency Matrix ===" << endl;
        cout << "   ";
        for (int i = 0; i < numVertices; i++)
            cout << i << " ";
        cout << endl;
        
        for (int i = 0; i < numVertices; i++) {
            cout << i << "  ";
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    bool checkEdge(int i, int j) {
        if (i >= numVertices || j >= numVertices || i < 0 || j < 0) {
            cout << "Invalid vertices!" << endl;
            return false;
        }
        return adjMatrix[i][j] == 1;
    }
};

int main() {
    cout << "welcome to the world of analysis of algorithm with umar ahad usmani (sap:60199)" << endl;
    cout << "this is the lab 10 task 2 - check if edge exists between two vertices" << endl;

    int vertices;
    cout << "\nEnter number of vertices: ";
    cin >> vertices;
    
    Graph g(vertices);
    
    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    
    cout << "\n=== Adding Edges ===" << endl;
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        cout << "Enter edge " << i + 1 << " (source destination): ";
        cin >> src >> dest;
        g.addEdge(src, dest);
    }
    
    g.printMatrix();
    
    cout << "\n=== Check Edge ===" << endl;
    int v1, v2;
    cout << "Enter two vertices to check edge (v1 v2): ";
    cin >> v1 >> v2;
    
    if (g.checkEdge(v1, v2)) {
        cout << "Edge exists between vertex " << v1 << " and vertex " << v2 << endl;
    } else {
        cout << "No edge exists between vertex " << v1 << " and vertex " << v2 << endl;
    }
    
    return 0;
}
