#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int rods(vector<int> r){
    int len=r.size();
    r.insert(r.begin(),0);
    vector<int> dp(len+1, 0);
    for(int i=1; i<=len; i++){
        for(int j=1; j<=i; j++){
            dp[i]=max(dp[i],r[j]+dp[i-j]);
        }
    }
    for(int i=0; i<dp.size(); i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
    return dp[len];
}

int main() {
    vector<int> rod{1,3,2,5};
    cout<<rods(rod);
}
