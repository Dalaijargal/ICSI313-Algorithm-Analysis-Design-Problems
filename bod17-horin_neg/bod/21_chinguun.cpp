#include <bits/stdc++.h>
using namespace std;

int dp[1000006];
int a[1000006];

int n, ans;


int go(int n){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    if(n <= 3) {
        dp[n] = INT_MIN;
        return dp[n];
    }

    dp[n] = max(go(n - 4) + (a[n] + a[n - 1] > a[n - 2] + a[n - 3] && a[n] + a[n - 1] <= 21), 
    go(n - 5) + (a[n] + a[n - 1] + a[n - 2] > a[n - 3] + a[n - 4] && a[n] + a[n - 1] + a[n - 2] <= 21));
    
    return dp[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        dp[i] = -1;
    }
    for(int i = n; i >= n - 3; i --){
        if(ans < go(i)) ans = go(i);
    }
    cout << ans << "\n";

}