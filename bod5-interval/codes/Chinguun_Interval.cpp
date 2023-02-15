#include <bits/stdc++.h>
using namespace std;

int n;
int dp[10000 + 5], w[10000 + 5];
vector <pair <pair <int, int>, int>> v;

int dp_o(int i, vector <pair <pair <int, int>, int>> v) {
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = 0;
    for(int j = i + 1; j <= n; j ++) {
        if(v[j].first.second > v[i].first.first) {
            ans = max(ans, dp_o(j, v) + v[j].second);
        }
    }
    return dp[i] = ans;
}

int main(){
    cin >> n; 
    memset(dp, -1, sizeof(dp));
    v.push_back(make_pair(make_pair(0, 0), 0));
    for(int i = 1; i <= n; i ++) {
        int l, r;
        cin >> w[i] >> l >> r;
        v.push_back(make_pair(make_pair(r, l), w[i]));
    }
    sort(v.begin(), v.end());
    // for(int i = 0; i < n; i ++) {
    //     cout << v[i].first.second << " " << v[i].first.first << " " << v[i].second << endl;
    // }
    cout << dp_o(0, v) << endl;
    // for(int i = 0; i <= n; i ++) {
    //     cout << dp[i] << " ";
    // }
    
    return 0;

}