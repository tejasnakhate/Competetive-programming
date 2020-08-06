#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int elephant(int n, int m){
    vector<vector<int> > v(n,vector<int>(m,0));
    v[0][0]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 and j==0){
            }
            else{
                int ans=0;
                for(int k=0; k<i; k++){
                    ans+=v[k][j];
                }
                for(int k=0; k<j; k++){
                    ans+=v[i][k];
                }
                v[i][j]=ans;
            }
        }
    }
    return v[n-2][m-1];
}

int main() {
    cout<<elephant(3,5);
}
