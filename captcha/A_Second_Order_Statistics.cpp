#include<iostream>
#include<bits/stdc++.h>
#include<string>    
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int>v;
    set<int>::iterator it;
    
    vector<int>arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        v.insert(arr[i]);
    }
    
    it=v.begin();
    ++it;
    if(v.size()==1){
        cout<<"NO";
    }
    else{
         cout<<*it;
    }
   
    
     
    
}