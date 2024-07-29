#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a;
    cin >> a;
    while(a>0){
        long long int l,r;
        cin>>l>>r;
        int count=0;
        if(l%2==0 && r%2==0){
            while(r%l!=0){
                r-=2;
            }
            while(l/2!=1){
                l=l/2;
                count++;
            }
            count+=1;
        }
        if(l%2!=0 && r%2!=0){
            while(r%l!=0){
                r-=2;
            }
            while(l/2!=1){
                l=l/2;
                count++;
            }
        }        
    }