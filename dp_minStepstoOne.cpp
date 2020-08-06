#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int min_ssteps_to_1(int n){
    int dp[n+1]={0};
    //base case
    dp[1]=0;
    for(int i=2; i<=n; i++){
        int prev=INT_MAX;
        if(i%2==0){
            prev=min(prev,dp[i/2]);
        }
        if(i%3==0){
            prev=min(prev,dp[i/3]);
        }
        dp[i]=min(prev,dp[i-1])+1;
    }
    return dp[n];
}

int main() {
    int n;
    cin>>n;
    cout<<min_ssteps_to_1(n);
}
