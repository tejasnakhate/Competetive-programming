#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool findpath(char maze[10][10],int sol[][10],int i, int j, int m, int n){
    if(i==m && j==n){1;
        sol[m][n]=1;
        //print path
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                cout<<sol[i][j]<<"  ";
            }
            cout<<endl;
        }cout<<endl;
        return true;
    }
    //make sure you are inside the grid
    if(i>m || j>n){
        return false;
    }
    if(maze[i][j]=='X'){
        return false;
    }

    //assume solution exists
    sol[i][j]=1;

    
    bool right=findpath(maze,sol,i+1,j,m,n);
    bool down=findpath(maze,sol,i,j+1,m,n);

    //backtracking
    sol[i][j]=0;
    if(!right && !down){
        return false;
    }
    else{
        return true;
    }
}


int main() {
    char maze[10][10]= {"0000",
                        "00X0",
                        "000X",
                        "0X00"};
    int sol[10][10]={0};
    int m=4, n=4;
    bool ans=findpath(maze,sol,0,0,m-1,n-1);
}
