#include<iostream>
#include<string>
using namespace std;

// Huffman Tree Node
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(char c, int f) {
    Node* node = new Node();
    node->ch = c;
    node->freq = f;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find minimum frequency node index in array
int findMin(Node* arr[], int n) {
    int minIndex = -1;
    int minFreq = 999999;
    for (int i = 0; i < n; i++) {
        if (arr[i] != NULL && arr[i]->freq < minFreq) {
            minFreq = arr[i]->freq;
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    cout << "Welcome to the world of analysis of algorithms with umar usmani sap: 60199" << endl;
    cout << "This is lab 12 task 2 - Build Huffman Tree using greedy algorithm and array" << endl;
    cout << endl;

    string text;
    cout << "Enter a string: ";
    getline(cin, text);
    cout << "Input string: " << text << endl;

    // Step 1: Calculate frequency of each character
    int freq[256] = {0};
    for (int i = 0; i < text.length(); i++) {
        freq[(int)text[i]]++;
    }

    // Step 2: Create array of leaf nodes
    Node* nodes[256];
    int nodeCount = 0;
    
    cout << "\nStep 1: Creating leaf nodes..." << endl;
    for (int i = 0; i < 256; i++) {
        nodes[i] = NULL;
        if (freq[i] > 0) {
            nodes[nodeCount] = createNode((char)i, freq[i]);
            cout << "  Leaf node: '" << (char)i << "' with frequency " << freq[i] << endl;
            nodeCount++;
        }
    }

    // Step 3: Build Huffman Tree by combining two lowest frequency nodes
    cout << "\nStep 2: Building Huffman Tree..." << endl;
    int step = 1;
    int remaining = nodeCount;
    
    while (remaining > 1) {
        // Find first minimum
        int min1 = findMin(nodes, nodeCount);
        Node* left = nodes[min1];
        nodes[min1] = NULL;
        
        // Find second minimum
        int min2 = findMin(nodes, nodeCount);
        Node* right = nodes[min2];
        nodes[min2] = NULL;
        
        cout << "  Combine step " << step++ << ": ";
        if (left->ch != '\0') cout << "'" << left->ch << "'";
        else cout << "[internal]";
        cout << "(" << left->freq << ") + ";
        if (right->ch != '\0') cout << "'" << right->ch << "'";
        else cout << "[internal]";
        cout << "(" << right->freq << ") = " << (left->freq + right->freq) << endl;
        
        // Create a new internal node with combined frequency
        Node* internal = createNode('\0', left->freq + right->freq);
        internal->left = left;
        internal->right = right;
        
        // Add the new node back to array
        nodes[nodeCount++] = internal;
        remaining--;
    }

    // The remaining node is the root of Huffman Tree
    Node* root = NULL;
    for (int i = 0; i < nodeCount; i++) {
        if (nodes[i] != NULL) {
            root = nodes[i];
            break;
        }
    }

   

    cout << "\nHuffman Tree built successfully!" << endl;
    cout << "Root frequency (total characters): " << root->freq << endl;

    return 0;
}
