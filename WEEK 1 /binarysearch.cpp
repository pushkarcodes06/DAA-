#include <iostream>
using namespace std;
int binarySearch(int a[], int low, int high, int key)
{
    if(low>high)
        return -1;
    int mid=(low+high)/ 2;
    if(a[mid]==key)
        return mid;
    if(key<a[mid])
        return binarySearch(a,low,mid-1,key);
    else
        return binarySearch(a,mid+1,high,key);
}

int main()
{
    int n,key;
    cout<< "Enter number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements in sorted order: ";
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cout<<"Enter element to search: ";
    cin>>key;
    int result=binarySearch(a,0,n-1,key);
    if(result!=-1)
        cout<<"Element found at index " << result;
    else
        cout<<"Element not found";
    return 0;
}
