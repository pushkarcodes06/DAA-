#include <bits/stdc++.h>
using namespace std;
 
vector<int> twoSum(vector<int> &arr, int target) {
    unordered_map<int, int> map;   // value -> index
 
    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[arr[i]] = i;
    }
    return {};   // no valid pair found
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
 
    int target;
    cout << "Enter target sum: ";
    cin >> target;
 
    vector<int> result = twoSum(arr, target);
 
    if (result.empty()) {
        cout << "No valid pair found." << endl;
    } else {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    }
 
    return 0;
}
