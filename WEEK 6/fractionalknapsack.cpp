#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int value;
    int weight;
};

bool comparison(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, W;
    if (!(cin >> n >> W)) return 0;

    vector<Item> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].value >> arr[i].weight;
    }

    sort(arr.begin(), arr.end(), comparison);

    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            finalValue += arr[i].value * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    cout << fixed << setprecision(2) << finalValue << "\n";

    return 0;
}
