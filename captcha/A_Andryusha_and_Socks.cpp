#include<iostream>
#include<bits/stdc++.h>
#include<string>    
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(2*n);
    for(int i=0;i<2*n;i++){
        cin>>v[i];
    }
    int max_size=0;
    unordered_set<int>table;
    for(int i=0;i<2*n;i++){
        if(table.count(v[i])==0){
            
            table.insert(v[i]);
        }
        else{
            table.erase(v[i]);
        }
        if(table.size()>max_size){
            max_size=table.size();
        }


    }
    cout<<max_size;
    
    
}
