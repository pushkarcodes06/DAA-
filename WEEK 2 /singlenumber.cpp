#include <iostream>
using namespace std;
int singlenumber(int a[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum^=a[i];
	}
	return sum;
}
int main(){
	int a[100],i,n;
	cout<<"enter size"<<endl;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int c=singlenumber(a,n);
	cout<<"singlenumber is"<<c<<endl;
	return 0;
}
