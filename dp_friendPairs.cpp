#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    int ans=1;
    if(n<=1){
        return ans;
    }
    for(int i=1; i<=n; i++){
        ans*=i;
    }
    return ans;
}

int friends(int n){
    vector<int> dp(n+1,1);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    if(n<=2){
        return dp[n];
    }
    for(int i=3; i<=n; i++){
        dp[i]=dp[i-1]+(fact(i-1)/(fact(1)*fact(i-2)))*dp[i-2]; 
    }
    return dp[n];
}

int main() {
    int n;
    cin>>n;
    cout<<friends(n)<<endl;
    cout<<fact(4);
}
