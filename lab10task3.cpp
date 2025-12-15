#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<int> adjLists[10];

public:
    Graph(int vertices) { 
        numVertices = vertices; 
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src); // Undirected graph
    }

    void printGraph() {
        cout << "\n=== Adjacency List ===" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ":";
            for (int j = 0; j < adjLists[i].size(); j++)
                cout << " -> " << adjLists[i][j];
            cout << endl;
        }
    }
};

int main() {
    cout << "welcome to the world of analysis of algorithm with umar ahad usmani (sap:60199)" << endl;
    cout << "this is the lab 10 task 3 - print adjacency list of undirected graph" << endl;

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
    
    g.printGraph();
    
    return 0;
}
