#include<iostream>
#include<bits/stdc++.h>
#include<string>    
using namespace std;

int main(){
    int n;
    cin>>n;

    while(n>0){
        int a,b;
        cin>>a>>b;
        string v;
        cin>>v;
        map<char,int>mp;
        
        
        for(int i=0;i<a;i++){
            mp[v[i]]++;
        }
        
        int sum=0,count=0;
        for(auto it:mp){
            count++;
            if(it.second<b){
             
                int val=b-it.second;
                sum+=val;
            } 
        }
        int ans=(7-count)*b;
        
        sum+=ans;
        cout<<sum<<endl;
        n--;
        
    }
}