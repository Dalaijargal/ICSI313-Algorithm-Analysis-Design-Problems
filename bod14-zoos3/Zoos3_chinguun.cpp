#include <bits/stdc++.h>
using namespace std;

int dp[10004][1003];
int n, m, price[1004], cost[1004];

int doit(int rst, int ind){
    if(rst == 0) return 0;
    if(ind == m) return 0;
    int i = 0, ans = -1;
    if(dp[rst][ind] != -1) return dp[rst][ind];
    while(rst >= i * cost[ind]){
        ans = max(ans, doit(rst - i * cost[ind], ind + 1) + i * price[ind]);
        i ++;
    }
    dp[rst][ind] = ans;
    return dp[rst][ind];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        cin >> cost[i] >> price[i];
    }
    memset(dp, -1, sizeof dp);
    cout << doit(n, 0) << "\n";
}
// n shirher adil mungun zaas
// m shirheg baraatai
// hailuulj baraa hiine
// p[i] unelgeetei
// c[i] oroh hemjee
// 
