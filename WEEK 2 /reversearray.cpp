#include<iostream>
using namespace std;
void reverse(int a[],int s, int e){
	while(s<e){
	   int temp=a[s];
	   a[s]=a[e];
	   a[e]=temp;
	   s++;
	   e--;
	}
}
void rotate(int a[],int k,int n){
	k=k%n;
	reverse(a,0,n-1);
	reverse(a,0,k-1);
	reverse(a,k,n-1);
}
int main(){
	int a[100],i,n,k;
	cout<<"enter size"<<endl;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"enter size should be reversed"<<endl;
	cin>>k;
	rotate(a,k,n);
		for(i=0;i<n;i++){
		cout<<a[i];
	}
return 0;	
}
