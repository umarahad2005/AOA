#include <iostream>
#include <string>
using namespace std;

void findPattern(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    bool found = false;

    cout << "Searching for pattern '" << pattern << "' in text..." << endl;

    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m) {
            if (!found) {
                cout << "Pattern found at positions: ";
                found = true;
            }
            cout << i << " ";
        }
    }

    if (!found)
        cout << "Pattern not found in the text.";

    cout << endl;
}

int main() {
    cout<<"welcome to the world of Analysis of Algorithms with umar ahad usmani sap(60199)"<<endl;

    string text, pattern;

    cout << "Enter the text string: ";
    getline(cin, text);

    cout << "Enter the pattern to search for: ";
    getline(cin, pattern);

    findPattern(text, pattern);

    return 0;
}
