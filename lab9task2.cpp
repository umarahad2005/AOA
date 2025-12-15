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

void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    cout << "welcome to the world of analysis of algorithm with umar ahad usmani (sap:60199)" << endl;
    cout << "this is the lab 9 task 2 in which we perform inorder, preorder, and postorder traversals" << endl;
    
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
    
    cout << "\n=== Tree Traversals ===" << endl;
    cout << "Preorder:  ";
    preorderTraversal(root);
    cout << endl;
    
    cout << "Inorder:   ";
    inorderTraversal(root);
    cout << endl;
    
    cout << "Postorder: ";
    postorderTraversal(root);
    cout << endl;
    
    return 0;
}
