#include <iostream>
using namespace std;
void findMaxMin(int a[], int low, int high, int &max, int &min)
{
    if (low == high)
    {
        max = min = a[low];
        return;
    }
    if (high == low + 1)
    {
        if (a[low] > a[high])
        {
            max = a[low];
            min = a[high];
        }
        else
        {
            max = a[high];
            min = a[low];
        }
        return;
    }
    int mid = (low + high) / 2;
    int max1, min1, max2, min2;
    findMaxMin(a, low, mid, max1, min1);
    findMaxMin(a, mid + 1, high, max2, min2);
    max = (max1 > max2) ? max1 : max2;
    min = (min1 < min2) ? min1 : min2;
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int max, min;
    findMaxMin(a, 0, n - 1, max, min);
    cout << "Maximum element = " << max << endl;
    cout << "Minimum element = " << min << endl;
    return 0;
}
