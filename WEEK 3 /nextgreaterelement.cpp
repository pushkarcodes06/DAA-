#include <bits/stdc++.h>
using namespace std;
 
vector<int> nextGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;   // stores indices
 
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            int j = st.top();
            st.pop();
            result[j] = arr[i];
        }
        st.push(i);
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
 
    vector<int> result = nextGreaterElement(arr);
 
    cout << "Next Greater Elements: ";
    for (int x : result) cout << x << " ";
    cout << endl;
 
    return 0;
}
