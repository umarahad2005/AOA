#include <iostream>
#include <vector>
using namespace std;

int knapsack01(vector<int>& values, vector<int>& weights, int capacity) {
    int n = values.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= capacity; w++) {
            if(weights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                int include = dp[i - 1][w - weights[i - 1]] + values[i - 1];
                int exclude = dp[i - 1][w];
                if(include > exclude) {
                    dp[i][w] = include;
                } else {
                    dp[i][w] = exclude;
                }
            }
        }
    }
    
    return dp[n][capacity];
}

int main() {
    cout << "welcome to the world of analysis of algorithm with umar ahad usmani (sap:60199)" << endl;
    
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    
    vector<int> values(n);
    vector<int> weights(n);
    
    for(int i = 0; i < n; i++) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> values[i] >> weights[i];
    }
    
    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    
    int maxValue = knapsack01(values, weights, capacity);
    
    cout << "Maximum Value = " << maxValue << endl;
    
    return 0;
}
