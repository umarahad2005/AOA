#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

int comparisonCount = 0;

bool isDominated(Point p1, Point p2) {
    comparisonCount++;
    if (p2.x >= p1.x && p2.y >= p1.y && (p2.x > p1.x || p2.y > p1.y)) {
        return true;
    }
    return false;
}

void bruteForceMaximalPoints(vector<Point>& points) {
    int n = points.size();
    vector<bool> isMaximal(n, true);
    
    cout << "\n--- Dominance Check Results ---" << endl;
    cout << "Point\t\tDominated By" << endl;
    cout << "-----\t\t------------" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << "(" << points[i].x << "," << points[i].y << ")\t\t";
        bool dominated = false;
        
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (isDominated(points[i], points[j])) {
                    isMaximal[i] = false;
                    cout << "(" << points[j].x << "," << points[j].y << ") ";
                    dominated = true;
                }
            }
        }
        
        if (!dominated) {
            cout << "None (Maximal)";
        }
        cout << endl;
    }
    
    cout << "\n--- Maximal Points ---" << endl;
    cout << "Maximal Points: ";
    for (int i = 0; i < n; i++) {
        if (isMaximal[i]) {
            cout << "(" << points[i].x << "," << points[i].y << ") ";
        }
    }
    cout << endl;
    
    cout << "\nTotal comparisons: " << comparisonCount << endl;
    cout << "Formula: n*(n-1) = " << n << "*" << (n-1) << " = " << n*(n-1) << endl;

}

int main() {
    cout << "welcome to the world of Analysis of Algorithms with umar ahad usmani sap(60199)" << endl;
    cout << "\n--- Brute Force Maximal Points Algorithm ---" << endl;
    
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    
    vector<Point> points(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Enter coordinates for Point " << i + 1 << " (x y): ";
        cin >> points[i].x >> points[i].y;
    }
    
    cout << "\n--- Input Points ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Point " << i + 1 << ": (" << points[i].x << "," << points[i].y << ")" << endl;
    }
    
    bruteForceMaximalPoints(points);
    
    return 0;
}
