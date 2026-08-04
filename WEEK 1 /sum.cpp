#include<iostream>
using namespace std;
int sum(int n);
void avg(int n);
int sum(int n)
{
    int s=0;
    for(int i=1;i<=n;i++)
    {
        s=s+i;
    }
    return s;
}
void avg(int n)
{
    int s=sum(n);
    float average=(float)s/n;
    cout<< "Average = " << average<<endl;
}
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Sum = " <<sum(n)<<endl;
    avg(n);
    return 0;
}
