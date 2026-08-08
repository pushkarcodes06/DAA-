#include <bits/stdc++.h>
using namespace std;
 
vector<int> slidingWindowMax(vector<int> &arr, int k) {
    deque<int> dq;     // stores indices, values in decreasing order
    vector<int> result;
    int n = arr.size();
 
    for (int i = 0; i < n; i++) {
        // remove smaller elements from the back
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
 
        dq.push_back(i);
 
        // remove front if it's outside the current window
        if (dq.front() <= i - k) {
            dq.pop_front();
        }
 
        // record max once the first window of size k is formed
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    return result;
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
 
    int k;
    cout << "Enter window size k: ";
    cin >> k;
 
    vector<int> result = slidingWindowMax(arr, k);
 
    cout << "Sliding window maximums: ";
    for (int x : result) cout << x << " ";
    cout << endl;
 
    return 0;
}
