#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

int countTotalNodes(Node* root) {
    if (root == nullptr) return 0;
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

int countLeafNodes(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countInternalNodes(Node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return 0;
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

int main() {
    cout << "welcome to the world of analysis of algorithm with umar ahad usmani (sap:60199)" << endl;
    cout << "this is the lab 9 task 3 in which we count nodes, leaf nodes, and internal nodes" << endl;
    
    Node* root = nullptr;
    cout << "\nEnter the number of elements to insert: ";
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        int val;
        cin >> val;
        root = insert(root, val);
    }
    
    cout << "\nBinary Search Tree created with " << n << " elements." << endl;
    
    int totalNodes = countTotalNodes(root);
    int leafNodes = countLeafNodes(root);
    int internalNodes = countInternalNodes(root);
    
    cout << "\n=== Node Counts ===" << endl;
    cout << "Total Nodes: " << totalNodes << endl;
    cout << "Leaf Nodes: " << leafNodes << endl;
    cout << "Internal Nodes: " << internalNodes << endl;
    
    return 0;
}
