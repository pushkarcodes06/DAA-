#include <bits/stdc++.h>
using namespace std;

void findSubsets(int index, const vector<int>& nums, int target, vector<int>& currentSubset, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(currentSubset);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        if (nums[i] > target) {
            break; 
        }

        currentSubset.push_back(nums[i]);
        findSubsets(i + 1, nums, target - nums[i], currentSubset, result);
        currentSubset.pop_back();
    }
}

int main() {
    vector<int> nums = {10, 7, 5, 18, 12, 2, 1};
    int target = 15;

    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    vector<int> currentSubset;

    findSubsets(0, nums, target, currentSubset, result);

    if (result.empty()) {
        cout << "No subset found with the given sum.\n";
    } else {
        cout << "Subsets with sum " << target << " are:\n";
        for (const auto& subset : result) {
            cout << "[ ";
            for (int num : subset) {
                cout << num << " ";
            }
            cout << "]\n";
        }
    }

    return 0;
}
