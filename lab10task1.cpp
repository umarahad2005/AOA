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
};

int main() {
    cout << "welcome to the world of analysis of algorithm with umar ahad usmani (sap:60199)" << endl;
    cout << "this is the lab 10 task 1 - create adjacency matrix for graph with 5 vertices and 4 edges" << endl;

    Graph g(5);
    
    int numEdges;
    cout << "\nEnter the number of edges: ";
    cin >> numEdges;
    
    cout << "\n=== Adding Edges ===" << endl;
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        cout << "Enter edge " << i + 1 << " (source destination): ";
        cin >> src >> dest;
        g.addEdge(src, dest);
    }
    
    g.printMatrix();
    
    return 0;
}
