#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;

    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Welcome to the world of Analysis of Algorithms with Umar Usmani (SAP: 60199)" << endl;
    cout << "Enter the number of steps in the staircase: ";
    cin >> n;
    cout << "Number of distinct ways to climb " << n << " steps = " << climbStairs(n) << endl;
    return 0;
}