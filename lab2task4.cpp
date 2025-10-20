#include <iostream>
#include <string>
#include <vector>
using namespace std;

void mySwap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void generatePermutations(string str, int start, int end, vector<string> &result) {
    if (start == end) {
        result.push_back(str);
        return;
    }

    for (int i = start; i <= end; i++) {
        mySwap(str[start], str[i]); 
        generatePermutations(str, start + 1, end, result);
        mySwap(str[start], str[i]); 
    }
}

void bubbleSort(vector<string> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    cout<<"welcome to the world of Analysis of Algorithms with umar ahad usmani sap(60199)"<<endl;

    string word;
    cout << "Enter a word: ";
    cin >> word;

    vector<string> permutations;
    generatePermutations(word, 0, word.length() - 1, permutations);

    bubbleSort(permutations);

    cout << "\nAll permutations of the word in alphabetical order:\n";
    for (int i = 0; i < permutations.size(); i++) {
        cout << permutations[i] << " ";
    }

    cout << endl;
    return 0;
}
