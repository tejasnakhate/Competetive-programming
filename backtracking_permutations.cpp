#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void permute(char *in, int i, set<string> &s){
    //base case
    if(in[i]=='\0'){
        // cout<<in<<",";
        string t(in);
        s.insert(t);
        return;
    }

    //recursive case
    for(int j=i; in[j]!='\0'; j++){
        swap(in[i],in[j]);
        permute(in,i+1,s);

        //backtracking
        swap(in[i],in[j]);
    }
}

int main() {
    char in[100]={};
    cin>>in;
    set<string> s;
    permute(in,0,s);
    
    for(auto x:s){
        cout<<x<<"  ";
    }
}
