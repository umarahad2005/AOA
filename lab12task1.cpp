#include<iostream>
#include<string>
using namespace std;

int main() {
    cout << "Welcome to the world of analysis of algorithms with umar usmani sap: 60199" << endl;
cout << "This is lab 12 task 1 Find the frequency of  character using array and character traversal" << endl;
string text;
    cout << "Enter a string: ";
    getline(cin, text); 
    cout << "Input string: " << text << endl;
 cout << "\nCharacter Frequencies:" << endl;
    int freq[256] = {0};
    for (int i = 0; i < text.length(); i++) {
        freq[(int)text[i]]++;
    }
     for (int i = 0; i < 256; i++) {
    if (freq[i] != 0) {
 cout << (char)i << " = " << freq[i] << endl;
    }
    }

    return 0;
}