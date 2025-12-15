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
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    
    return root;
}

int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

int findMax(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}

int main() {
    cout << "welcome to the world of analysis of algorithm with umar ahad usmani (sap:60199)" << endl;
    cout << "this is the lab 9 task 6 - find minimum and maximum in BST" << endl;
    
    Node* root = nullptr;
    cout << "\nEnter the number of elements to insert: ";
    int n;
    cin >> n;
    
    cout << "\n=== Inserting into BST ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        int val;
        cin >> val;
        root = insert(root, val);
    }
    
    cout << "\nBinary Search Tree created with " << n << " elements." << endl;
    
    cout << "\n=== Finding Min and Max ===" << endl;
    cout << "Minimum element: " << findMin(root) << endl;
    cout << "Maximum element: " << findMax(root) << endl;
    
    return 0;
}
