#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int id;
    int start;
    int finish;
};

bool comparison(Activity a, Activity b) {
    return (a.finish < b.finish);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Activity> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].id = i + 1;
        cin >> arr[i].start >> arr[i].finish;
    }

    sort(arr.begin(), arr.end(), comparison);

    vector<int> selectedActivities;
    
    if (n > 0) {
        selectedActivities.push_back(arr[0].id);
        int lastFinishTime = arr[0].finish;

        for (int i = 1; i < n; i++) {
            if (arr[i].start >= lastFinishTime) {
                selectedActivities.push_back(arr[i].id);
                lastFinishTime = arr[i].finish;
            }
        }
    }

    cout << selectedActivities.size() << "\n";
    for (int i = 0; i < selectedActivities.size(); i++) {
        cout << selectedActivities[i] << " ";
    }
    cout << "\n";

    return 0;
}
