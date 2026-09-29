#include <bits/stdc++.h>
using namespace std;
 
int matrixChainOrder(vector<int> &p, int n) {
    // dp[i][j] = minimum cost to multiply matrices i through j
    vector<vector<int>> dp(n, vector<int>(n, 0));
 
    for (int len = 2; len < n; len++) {           // chain length
        for (int i = 1; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
 
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
 
    return dp[1][n - 1];
}
 
int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
 
    vector<int> p(n + 1);
    cout << "Enter " << (n + 1) << " dimensions (matrix i is p[i-1] x p[i]): ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }
 
    int result = matrixChainOrder(p, n + 1);
 
    cout << "Minimum number of multiplications: " << result << endl;
 
    return 0;
}
