#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
vector<int> v;
map<int, int> mp;
vector<int> dp;

int rec(int x) {
    if (x >= dp.size()) {
        return 0;
    }
    if (dp[x] != -1) {
        return dp[x];
    }

    return dp[x] = max(rec(x + 1), rec(x + 2) + mp[x] * x);
}

int main() {
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        mp[v[i]]++;
    }

    int max_val = *max_element(v.begin(), v.end());
    dp.resize(max_val + 1, -1);

    int ans = rec(1);

    cout << ans << endl;

    return 0;
}
