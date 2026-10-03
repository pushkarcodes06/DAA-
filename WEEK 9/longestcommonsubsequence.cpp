#include <bits/stdc++.h>
using namespace std;
 
int longestConsecutive(vector<int> &arr) {
    unordered_set<int> numSet(arr.begin(), arr.end());
    int longest = 0;
 
    for (int x : numSet) {
        // only start counting if x is the beginning of a sequence
        if (numSet.find(x - 1) == numSet.end()) {
            int length = 1;
            while (numSet.find(x + length) != numSet.end()) {
                length++;
            }
            longest = max(longest, length);
        }
    }
    return longest;
}
 
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
 
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    cout << "Longest consecutive sequence length: " << longestConsecutive(arr) << endl;
 
    return 0;
}
