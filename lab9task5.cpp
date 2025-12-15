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

bool searchBST(Node* root, int val) {
    if (root == nullptr) return false;
    if (root->data == val) return true;
    
    if (val < root->data) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    cout << "welcome to the world of analysis of algorithm with umar ahad usmani (sap:60199)" << endl;
    cout << "this is the lab 9 task 5 - BST operations (insert, search, display)" << endl;
    
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
    
    cout << "\n=== Inorder Traversal (Sorted Order) ===" << endl;
    cout << "Inorder Traversal (sorted): ";
    inorderTraversal(root);
    cout << endl;
    
    cout << "\n=== Searching in BST ===" << endl;
    cout << "Enter value to search: ";
    int searchVal;
    cin >> searchVal;
    if (searchBST(root, searchVal)) {
        cout << "Element " << searchVal << " found in BST." << endl;
    } else {
        cout << "Element " << searchVal << " not found in BST." << endl;
    }
    
    return 0;
}
