#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//cell Mitiosis problem Hackerblocks
long long cellMitiosis(int n, int x, int y, int z){

    vector<long long> dp(n+1,0);
    dp[0]=0;
    dp[1]=0;

    for(int i=2; i<=n; i++){
        //even case
        if(i%2==0){
            dp[i]=min(dp[i/2]+x,dp[i-1]+y);
        }
        //oddcase
        else{
            dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
        }
    }
    return dp[n];
}

int main() {
    cout<<cellMitiosis(5,2,1,3);
}
