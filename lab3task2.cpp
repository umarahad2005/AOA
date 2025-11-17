#include <iostream>
#include <vector>
#include <string>
using namespace std;

int comparisonCount = 0;

struct Patient {
    string id;
    int urgencyScore;
};

int partition(vector<Patient>& patients, int left, int right) {
    int pivot = patients[right].urgencyScore;
    int i = left - 1;
    
    for (int j = left; j < right; j++) {
        comparisonCount++;
        if (patients[j].urgencyScore <= pivot) {
            i++;
            swap(patients[i], patients[j]);
        }
    }
    swap(patients[i + 1], patients[right]);
    return i + 1;
}

void quick_sort(vector<Patient>& patients, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(patients, left, right);
        quick_sort(patients, left, pivotIndex - 1);
        quick_sort(patients, pivotIndex + 1, right);
    }
}

int main() {
    cout << "Welcome to CityCare Multi-Specialty Hospital - Patient Management System" << endl;
    cout << "This system uses Quick Sort " << endl << endl;
    
    int n;
    cout << "Enter number of patients: ";
    cin >> n;
    cout << endl;
    
    vector<Patient> patients(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Enter details for Patient " << i + 1 << ":" << endl;
        cout << "Enter Patient ID: ";
        cin >> patients[i].id;
        cout << "Enter Urgency Score (lower = more critical): ";
        cin >> patients[i].urgencyScore;
        cout << endl;
    }
    
    quick_sort(patients, 0, n - 1);
    
    cout << "--- Sorted Patient Records (by urgency) ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Patient ID: " << patients[i].id << ", Urgency Score: " << patients[i].urgencyScore << endl;
    }
    cout << endl;
    cout << "Time Complexity: O(n log n)" << endl;
    cout << "Total number of comparisons: " << comparisonCount << endl;
    
    return 0;
}
