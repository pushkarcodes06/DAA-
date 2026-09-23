#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Job> arr(n);
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }

    sort(arr.begin(), arr.end(), comparison);

    vector<char> slot(maxDeadline + 1, ' ');
    int countJobs = 0, totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline; j > 0; j--) {
            if (slot[j] == ' ') {
                slot[j] = arr[i].id;
                countJobs++;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    cout << countJobs << " " << totalProfit << "\n";
    for (int j = 1; j <= maxDeadline; j++) {
        if (slot[j] != ' ') {
            cout << slot[j] << " ";
        }
    }
    cout << "\n";

    return 0;
}
