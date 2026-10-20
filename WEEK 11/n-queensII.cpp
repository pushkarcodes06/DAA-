#include <bits/stdc++.h>
using namespace std;
 
// colUsed[c]            : is column c occupied?
// diag1[row + col]      : is this "/" diagonal occupied?
// diag2[row - col+n-1]  : is this "\" diagonal occupied?
int countSolutions(int row, int n, vector<bool> &colUsed,
                   vector<bool> &diag1, vector<bool> &diag2) {
    if (row == n) return 1;                      // one complete arrangement
 
    int count = 0;
    for (int c = 0; c < n; c++) {
        int d1 = row + c;
        int d2 = row - c + n - 1;
 
        if (colUsed[c] || diag1[d1] || diag2[d2]) continue;   // prune
 
        colUsed[c] = true;                       // choose
        diag1[d1] = true;
        diag2[d2] = true;
 
        count += countSolutions(row + 1, n, colUsed, diag1, diag2);
 
        colUsed[c] = false;                      // un-choose (backtrack)
        diag1[d1] = false;
        diag2[d2] = false;
    }
    return count;
}
 
int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;
 
    vector<bool> colUsed(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);
 
    cout << "Number of distinct solutions for N = " << n << ": "
         << countSolutions(0, n, colUsed, diag1, diag2) << endl;
 
    return 0;
}
