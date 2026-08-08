#include <bits/stdc++.h>
using namespace std;
 
int singleNumber(vector<int> &nums) {
    int result = 0;
    for (int x : nums) {
        result ^= x;
    }
    return result;
}
 
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
 
    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
 
    cout << "Single number: " << singleNumber(nums) << endl;
 
    return 0;
