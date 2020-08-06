#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int numberOfWaysToGetChange(int amount, vector<int>& coins) {
        coins.insert(coins.begin(),0);
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1, -1));
        for(int i=0; i<coins.size(); i++){
            for(int j=0; j<=amount; j++){
                if(i==0){
                    dp[i][j]=0;
                }
                if(j==0){
                    dp[i][j]=1;
                }
            }
        }
        for(int i=1; i<coins.size(); i++){
            for(int j=1; j<=amount; j++){
                if(j-coins[i]>=0 && dp[i][j-coins[i]]!=-1){
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }/*
        for(int i=0; i<coins.size(); i++){
            for(int j=0; j<=amount; j++){
                cout<<dp[i][j]<<"   ";
            }
            
            cout<<endl;
        }*/
        // return 1;
        return dp[coins.size()-1][amount];
    }
int main() {
    vector<int> coins{2,5,15};
    int amount=25;
    cout<<numberOfWaysToGetChange(amount,coins)<<endl;
}
