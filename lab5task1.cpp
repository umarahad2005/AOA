#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout<<"welcome to the world of analysis of algorithm with umar usmani (sap:60199)  "<<endl;
    cout << "Enter the number of index  you looking for Fibonacci: ";
    cin >> n;
    cout << "Fibonacci at the index (" << n << ") is =  " << fibonacci(n) << endl;
    return 0;
}