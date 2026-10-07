//code for n queens problem
#include<bits/stdc++.h>
using namespace std;

bool safe(int row,int c,vector<int> &col){
    for(int r=0;r<row;r++){
        if(col[r] == c)return false;
        if(abs(col[r] - c) == abs(r - row))return false;

    } return true;
}

bool solveNqueens(int row,vector<int> &col,int N){
    if(row == N)return true;
    for(int c=0;c<N;c++){
        if(safe(row,c,col)){
            col[row] = c;
        if(solveNqueens(row+1,col,N)) return true;
         col[row] = 1;
        } 
    }return false;
}

int main(){
    int N;
    cout<<"Enter N:";
    cin>>N;

    vector<int> col(N,-1);

    if(solveNqueens(0,col,N)){
        cout<<"Solution :\n";

        for(int row =0;row<N;row++){
            for(int c=0;c<N;c++){
                cout<<(col[row] ==c?"Q":".");
            }cout<<"\n";
        }
    }else{
        cout<<"NO solution\n";
    }
    return 0;
}
