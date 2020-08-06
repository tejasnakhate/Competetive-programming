#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool safe(int board[][10], int i, int j, int n){
    //check for column
    for(int row=0; row<i; row++){
        if(board[row][j]==1){
            return false;
        }
    }

    //check for top left diagonal
    int x=i; int y=j;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--; y--;
    }

    //check for top right diagonal
    x=i; y=j;
    while(x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--; y++;
    }

    //position is safe
    return true;
}

bool nqueen(int board[][10], int i, int n){
    //base case
    if(i==n){
        //print board
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }cout<<endl;
        return false;
    }

    //recursive case
    //place queen in current row and call the remaining board
    for(int j=0; j<n; j++){
        //check if i,j position is safe
        if(safe(board,i,j,n)){
            //assume position is right
            board[i][j]=1;

            bool next_queen_possible=nqueen(board,i+1,n);
            if(next_queen_possible){
                return true;
            }
            else{
                //backtracking-assumption was wrong
                board[i][j]=0;
            }
        }
    }
    //tried for all pos in curr row but no success
    return false;
}

int main() {
    int n; cin>>n;
    int board[10][10]={0};
    nqueen(board,0,n);
}
