#include <iostream>
#include <string>
using namespace std;

int main() {
    cout<<"welcome to the world of Analysis of Algorithms with umar ahad usmani sap(60199)"<<endl;

    string str;
    cout << "Enter a string: ";
    cin >> str;

    int freq[256] = {0}; 
    for (int i = 0; i < str.length(); i++) {
        freq[(unsigned char)str[i]]++;
    }

    cout << "Character frequencies:\n";
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            cout << (char)i << " = " << freq[i] << endl;
        }
    }

    return 0;
}
