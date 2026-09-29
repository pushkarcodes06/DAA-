#include <bits/stdc++.h>
using namespace std;
 
int climbStairs(int n) {
    if (n <= 2) return n;
 
    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
 
int main() {
    int n;
    cout << "Enter number of steps N: ";
    cin >> n;
 
    cout << "Distinct ways to climb " << n << " steps: " << climbStairs(n) << endl;
 
    return 0;
}
