#include <iostream>
using namespace std;

int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;
    cout << "Welcome to the world of Analysis of Algorithms with Umar Usmani (SAP: 60199)" << endl;
    cout << "Enter number of items: ";
    cin >> n;

    int weights[n], values[n];
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> weights[i];
        cout << "Item " << i + 1 << " - Value: ";
        cin >> values[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int maxValue = knapsack(weights, values, n, capacity);
    cout << "Maximum value that can be carried = " << maxValue << endl;
    return 0;
}