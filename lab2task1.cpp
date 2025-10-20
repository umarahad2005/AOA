#include <iostream>
#include <vector>
using namespace std;

void linearSearch(const vector<int>& vec, int target) {
    bool found = false;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            cout << "Element " << target << " found at index " << i << "." << endl;
            found = true;
            return;
        }
    }

    if (!found) {
        cout << "Element " << target << " not found in the vector." << endl;
    }
}

int main() {
    cout<<"welcome to the world of Analysis of Algorithms with umar ahad usmani sap(60199)"<<endl;
    int size;
    cout << "Enter the size of the list: ";
    cin >> size;

    vector<int> numbers(size);

    cout << "Enter " << size << " elements for the list:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    int target;
    cout << "Enter the element to search for: ";
    cin >> target;

    linearSearch(numbers, target);

    return 0;
}
