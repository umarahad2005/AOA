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

Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteBST(Node* root, int val) {
    if (root == nullptr) return root;
    
    if (val < root->data) {
        root->left = deleteBST(root->left, val);
    } else if (val > root->data) {
        root->right = deleteBST(root->right, val);
    } else {
        // Case 1: Node with no child (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: Node with one child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node with two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    cout << "welcome to the world of analysis of algorithm with umar ahad usmani (sap:60199)" << endl;
    cout << "this is the lab 9 task 7 - delete a node from BST" << endl;
    
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
    
    cout << "\n=== Before Deletion ===" << endl;
    cout << "Inorder: ";
    inorderTraversal(root);
    cout << endl;
    
    cout << "\n=== Deleting Node ===" << endl;
    cout << "Enter value to delete: ";
    int deleteVal;
    cin >> deleteVal;
    root = deleteBST(root, deleteVal);
    cout << "Node " << deleteVal << " deleted." << endl;
    
    cout << "\n=== After Deletion ===" << endl;
    cout << "Inorder after deletion: ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}
