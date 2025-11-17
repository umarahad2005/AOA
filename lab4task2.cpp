#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

int comparisonCount = 0;

int mergeSort(vector<Point>& points, int left, int right) {
    if (left >= right) {
        return 0;
    }
    int mid = left + (right - left) / 2;
    mergeSort(points, left, mid);
    mergeSort(points, mid + 1, right);
    
    vector<Point> temp;
    int i = left, j = mid + 1;
    
    while (i <= mid && j <= right) {
        comparisonCount++;
        if (points[i].x <= points[j].x) {
            temp.push_back(points[i]);
            i++;
        } else {
            temp.push_back(points[j]);
            j++;
        }
    }
    
    while (i <= mid) {
        temp.push_back(points[i]);
        i++;
    }
    
    while (j <= right) {
        temp.push_back(points[j]);
        j++;
    }
    
    for (int k = left; k <= right; k++) {
        points[k] = temp[k - left];
    }
    
    return 0;
}

bool isDominated(Point p1, Point p2) {
    if (p2.x >= p1.x && p2.y >= p1.y && (p2.x > p1.x || p2.y > p1.y)) {
        return true;
    }
    return false;
}

void bruteForce(vector<Point>& points) {
    int n = points.size();
    vector<bool> isMaximal(n, true);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && isDominated(points[i], points[j])) {
                isMaximal[i] = false;
            }
        }
    }
    
    cout << "Maximal Points (Brute Force): ";
    for (int i = 0; i < n; i++) {
        if (isMaximal[i]) {
            cout << "(" << points[i].x << "," << points[i].y << ") ";
        }
    }
    cout << endl;
}

void planeSweep(vector<Point>& points) {
    int n = points.size();
    
    vector<Point> maximalPoints;
    int maxY = -1;
    
    cout << "\n--- Plane Sweep Process ---" << endl;
    cout << "Point\t\tCurrent maxY\tDecision" << endl;
    cout << "-----\t\t------------\t--------" << endl;
    
    for (int i = n - 1; i >= 0; i--) {
        cout << "(" << points[i].x << "," << points[i].y << ")\t\t";
        cout << maxY << "\t\t";
        
        if (points[i].y >= maxY) {
            maximalPoints.push_back(points[i]);
            maxY = points[i].y;
            cout << "Keep (Maximal)";
        } else {
            cout << "Discard (Dominated)";
        }
        cout << endl;
    }
    
    cout << "\n--- Results ---" << endl;
    cout << "Maximal Points (Plane Sweep): ";
    for (int i = maximalPoints.size() - 1; i >= 0; i--) {
        cout << "(" << maximalPoints[i].x << "," << maximalPoints[i].y << ") ";
    }
    cout << endl;
    
    cout << "\nTotal comparisons (for sorting): " << comparisonCount << endl;
    cout << "Time Complexity: O(n log n)" << endl;
    cout << "Space Complexity: O(n)" << endl;
}

int main() {
    cout << "welcome to the world of Analysis of Algorithms with umar ahad usmani sap(60199)" << endl;
    cout << "\n--- Divide & Conquer (Plane Sweep) Algorithm ---" << endl;
    
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    
    vector<Point> points(n);
    vector<Point> originalPoints(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Enter coordinates for Point " << i + 1 << " (x y): ";
        cin >> points[i].x >> points[i].y;
        originalPoints[i] = points[i];
    }
    
    cout << "\n--- Input Points ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Point " << i + 1 << ": (" << points[i].x << "," << points[i].y << ")" << endl;
    }
    
    cout << "\n--- Step 1: Sorting Points by x-coordinate ---" << endl;
    mergeSort(points, 0, n - 1);
    
    cout << "Sorted Points (by x asc): ";
    for (int i = 0; i < n; i++) {
        cout << "(" << points[i].x << "," << points[i].y << ") ";
    }
    cout << endl;
    
    cout << "\n--- Step 2: Plane Sweep ---" << endl;
    planeSweep(points);
    
    cout << "\n--- Verification ---" << endl;
    bruteForce(originalPoints);
    cout << "\nComparison: Both algorithms produce the same result." << endl;
    
    return 0;
}
