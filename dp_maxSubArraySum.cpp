#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int max_sumSubArrray(vector<int> a){
    bool all_not_negative=false;
    int mx2=0;
    int mx=0;  
    for(int i=1; i<a.size(); i++){
        all_not_negative=(a[i]>0)? true: all_not_negative;
        mx2 += a[i];
        mx2=(mx2<0)? 0:mx2;
        mx=max(mx,mx2);
    }
    if(all_not_negative){
        return mx;    
    }
    else{
        //only if we need to give some output
        //because in case all negative output
        //of the above code will be zero
        int mx=a[0];
        for(int i=1; i<a.size(); i++){
            mx=max(mx,a[i]);
        }
        return mx;
    }
}

int main() {
    vector<int> a{-3,2,5,-1,6,3,-2,7,-5,2};
    cout<<max_sumSubArrray(a)<<endl;
}
