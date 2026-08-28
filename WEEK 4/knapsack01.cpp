#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack01(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int w = W; w >= weights[i]; --w) {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }
    return dp[W];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, W;
    if (!(cin >> n >> W)) return 0;

    vector<int> values(n);
    vector<int> weights(n);

    for (int i = 0; i < n; ++i) cin >> values[i];
    for (int i = 0; i < n; ++i) cin >> weights[i];

    cout << knapsack01(W, weights, values, n) << "\n";

    return 0;
}
