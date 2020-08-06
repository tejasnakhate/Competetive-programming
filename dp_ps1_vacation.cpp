#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int vacation(int n, vector<vector<int> > v){
    vector<vector<int> > dp(n+1,vector<int>(3,0));
    dp[1][0]=v[1][0];
    dp[1][1]=v[1][1];
    dp[1][2]=v[1][2];
    for(int i=2; i<=n; i++){
        dp[i][0]=v[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=v[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=v[i][2]+max(dp[i-1][0],dp[i-1][1]);
    }
    return max(dp[n][0],max(dp[n][1],dp[n][2]));
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > v(n+1,vector<int>(3,0));
    for(int i=1; i<=n; i++){
        cin>>v[i][0];
        cin>>v[i][1];
        cin>>v[i][2];
    }
    cout<<vacation(n,v);
}
