#include <bits/stdc++.h>
using namespace std;

int zoos, n, c[15];
long long dp[10004][15];

long long doit(int sum, int pos){
    if(sum == 0) {
        dp[sum][pos] = 1;
        return dp[sum][pos];
    }
    if(pos == zoos) return 0;

    if(dp[sum][pos] != -1) return dp[sum][pos];
    int i = 0; long long ans = 0;
    while(sum >= i * c[pos]){
        ans += doit(sum - c[pos] * i, pos + 1);
        i ++;
    }
    dp[sum][pos] = ans;
    return dp[sum][pos];
}

int main(){
    cin >> zoos >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < zoos; i ++) cin >> c[i];
    sort(c, c + zoos, greater<int>());
    cout << doit(n, 0) << "\n";
    return 0;
}