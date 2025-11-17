#include <iostream>
#include <string>
using namespace std;

bool crackPassword(string current, const string& target, const string& charset, int maxLength, int& attempts) {
    if (current == target) {
        cout << "Password found: " << current << endl;
        return true;
    }

    if (current.length() >= maxLength)
        return false;

    for (char c : charset) {
        attempts++;
        string next = current + c;

        if (next == target) {
            cout << "Password found: " << next << endl;
            return true;
        }

        if (crackPassword(next, target, charset, maxLength, attempts))
            return true;
    }

    return false;
}

int main() {
    cout << "Welcome to the world of Analysis of Algorithms with Umar Ahad Usmani (SAP: 60199)" << endl;

    string target;
    cout << "Enter the numeric password to crack (max 3 digits, only 0 to 9): ";
    cin >> target;

    string charset = "0123456789";
    int attempts = 0;
    int maxLength = 3;

    cout << "Starting brute-force cracking..." << endl;

    if (crackPassword("", target, charset, maxLength, attempts))
        cout << "Number of attempts before finding the correct password: " << attempts << endl;
    else
        cout << "Password not found within the allowed length." << endl;

    return 0;
}
