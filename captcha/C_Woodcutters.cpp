#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long long int n;
vector<pair<long long int,long long int>> v;
int dp[100001][2];

int rec(long long int index, int lastfallen) {
    if (index == n) return 0;
    if(dp[index][lastfallen]!=-1){
        return dp[index][lastfallen];
            }
    int sol = max(rec(index + 1, 0), rec(index + 1, 1));

    if (index == 0 || (lastfallen == 1 && v[index].first - v[index - 1].first - v[index - 1].second > v[index].second) ||
        (lastfallen == 0 && v[index].first - v[index - 1].first > v[index].second)) {
        sol = max(sol, rec(index + 1, 0) + 1);
    }

    if (index == n - 1 || v[index + 1].first - v[index].first > v[index].second) {
        sol = max(sol, rec(index + 1, 1) + 1);
    }

    return dp[index][lastfallen]=sol;
}

int main() {
    cin >> n;

    v.resize(n);  
    for (int i = 0; i < 100001; ++i) {
    dp[i][0] = dp[i][1] = -1;
}
    for (auto& it : v) {
        cin >> it.first >> it.second;
    }

    cout<<rec(0, 0)<<endl; 

    return 0;
}
