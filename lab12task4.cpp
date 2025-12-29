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

// Function to find minimum frequency node index
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

// Array to store Huffman codes
string huffmanCodes[256];

// Function to generate Huffman codes
void generateCodes(Node* root, string code) {
    if (root == NULL) return;
    
    if (root->ch != '\0') {
        huffmanCodes[(int)root->ch] = code;
        return;
    }
    
    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

// Function to build Huffman Tree
Node* buildHuffmanTree(int freq[]) {
    Node* nodes[256];
    int nodeCount = 0;
    
    for (int i = 0; i < 256; i++) {
        nodes[i] = NULL;
        if (freq[i] > 0) {
            nodes[nodeCount++] = createNode((char)i, freq[i]);
        }
    }
    
    int remaining = nodeCount;
    
    while (remaining > 1) {
        int min1 = findMin(nodes, nodeCount);
        Node* left = nodes[min1];
        nodes[min1] = NULL;
        
        int min2 = findMin(nodes, nodeCount);
        Node* right = nodes[min2];
        nodes[min2] = NULL;
        
        Node* internal = createNode('\0', left->freq + right->freq);
        internal->left = left;
        internal->right = right;
        
        nodes[nodeCount++] = internal;
        remaining--;
    }
    
    for (int i = 0; i < nodeCount; i++) {
        if (nodes[i] != NULL) return nodes[i];
    }
    return NULL;
}

// Function to encode a string using Huffman codes
string encodeString(string text) {
    string encoded = "";
    for (int i = 0; i < text.length(); i++) {
        encoded += huffmanCodes[(int)text[i]];
    }
    return encoded;
}

int main() {
    cout << "Welcome to the world of analysis of algorithms with umar usmani sap: 60199" << endl;
    cout << "This is lab 12 task 4 - Encode a string using Huffman codes" << endl;
    cout << endl;

    string text;
    cout << "Enter a string: ";
    getline(cin, text);
    cout << "Input string: " << text << endl;

    // Step 1: Calculate frequency
    int freq[256] = {0};
    for (int i = 0; i < text.length(); i++) {
        freq[(int)text[i]]++;
    }

    // Step 2: Build Huffman Tree
    Node* root = buildHuffmanTree(freq);

    // Step 3: Generate Huffman Codes
    for (int i = 0; i < 256; i++) huffmanCodes[i] = "";
    generateCodes(root, "");

    cout << "\n=== Huffman Codes ===" << endl;
    bool printed[256] = {false};
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (!printed[(int)ch]) {
            cout << ch << " : " << huffmanCodes[(int)ch] << endl;
            printed[(int)ch] = true;
        }
    }

    // Step 4: Encode the string
    string encodedString = encodeString(text);

    cout << "\n=== Encoding Process ===" << endl;
    cout << "Original text: " << text << endl;
    cout << "\nCharacter by character encoding:" << endl;
    for (int i = 0; i < text.length(); i++) {
        cout << "  '" << text[i] << "' -> " << huffmanCodes[(int)text[i]] << endl;
    }

    cout << "\n=== Result ===" << endl;
    cout << "Encoded string: " << encodedString << endl;
    cout << "Encoded length: " << encodedString.length() << " bits" << endl;
    cout << "Original size:  " << text.length() * 8 << " bits (8 bits per character)" << endl;
    cout << "Compression:    " << (100.0 - (encodedString.length() * 100.0 / (text.length() * 8))) << "% saved" << endl;

    return 0;
}
