#include <bits/stdc++.h>
using namespace std;
 
int knapsack(vector<int> &weights, vector<int> &values, int n, int W) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
 
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];                 // item doesn't fit
            } else {
                dp[i][w] = max(dp[i - 1][w],                                        // exclude
                                values[i - 1] + dp[i - 1][w - weights[i - 1]]);      // include
            }
        }
    }
    return dp[n][W];
}
 
int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
 
    vector<int> weights(n), values(n);
    cout << "Enter " << n << " weights: ";
    for (int i = 0; i < n; i++) cin >> weights[i];
 
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) cin >> values[i];
 
    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;
 
    cout << "Maximum value: " << knapsack(weights, values, n, W) << endl;
 
    return 0;
}
