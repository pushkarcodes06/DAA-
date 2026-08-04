#include<iostream>
using namespace std;
bool ispoweroftwo (int n){
	return(n>0)&&((n&(n-1))==0);
	}
	int main(){
		int n;
		cin>>n;
		if (ispoweroftwo(n))
		cout<<"power of two";
		else
		cout<<"not a power of 2";
		return 0;
	}
