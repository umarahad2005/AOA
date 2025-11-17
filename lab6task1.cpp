#include <iostream>
#include <vector>
using namespace std;

void coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(coins[j] < coins[j + 1]) {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }
    
    vector<int> result;
    int totalCoins = 0;
    
    for(int i = 0; i < n && amount > 0; i++) {
        while(amount >= coins[i]) {
            amount -= coins[i];
            result.push_back(coins[i]);
            totalCoins++;
        }
    }
    
    cout << "Coins used: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    cout << "Total Coins: " << totalCoins << endl;
}

int main() {
    cout << "welcome to the world of analysis of algorithm with umar ahad usmani (sap:60199)" << endl;
    
    int n;
    cout << "Enter number of coin denominations: ";
    cin >> n;
    
    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    int amount;
    cout << "Enter amount: ";
    cin >> amount;
    
    coinChange(coins, amount);
    
    return 0;
}
