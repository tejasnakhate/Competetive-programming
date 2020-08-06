#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int hist(vector<int> a){
    stack<int> s;
    int l=-1,r=-1, ans=0, i=0;
    for(i; i<a.size();){
        if(s.empty()){
            s.push(i);
            i++;
            cout<<"a: "<<endl;
        }
        else if(a[i]>=a[s.top()])
        {
            s.push(i);
            i++;
            cout<<"b"<<endl;
        }
        else if(a[i]<a[s.top()]){
            r=i;
            cout<<"c"<<endl;
            int h=a[s.top()]; s.pop();
            if(s.empty()){
               ans=max(ans,h*i); 
            }
            else{
                l=s.top();
                ans=max(ans,h*(r-l-1));
            }
            cout<<"ans: "<<ans<<endl;
        }
    }
    stack<int>s1=s;
    while(!s1.empty()){
        cout<<s1.top()<<"   ";
        s1.pop();
    }
    cout<<endl;
    while(!s.empty()){
        r=i;
        int h=a[s.top()]; s.pop();
        if(s.empty()){
           ans=max(ans,h*i); 
        }
        else{
            l=s.top();
            ans=max(ans,h*(r-l-1));
        }
        cout<<"ans1: "<<ans<<endl;
    }
    return ans;
}

int main() {
    vector<int> a{2,1,2,3,1};
    cout<<hist(a);
}
