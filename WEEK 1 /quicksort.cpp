#include<iostream>
using namespace std;
int partition(int a[], int low, int high)
{
    int pivot=a[low];
    int i=low + 1;
    int j=high;
    while(i<=j)
    {
        while(i<=high&&a[i]<=pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j)
            swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}
void quickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int p=partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    quickSort(a,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" "; 
    return 0;
}
