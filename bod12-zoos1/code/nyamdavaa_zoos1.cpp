#include<bits/stdc++.h>
using namespace std ; 

int main () {
    int n ; cin >> n ; 
    int dp[n+1] ; 
    for (int i = 0 ; i <= n ; i ++) {
        dp[i] = INT_MAX ; 
    }
   
    dp[2] = 1 ; 
    dp[3] = 1 ; 
    dp[4] = 2 ; 
    dp[5] = 1 ; 

    for (int i = 6 ; i <= n ; i ++) {
        dp[i] = min({dp[i], dp[i-2] + 1, dp[i-3] + 1, dp[i-5] + 1}) ; 
    }
    if (dp[n] == INT_MAX) {
        cout << -1 << endl ; 
    }
    else {
        cout << dp[n] << endl ; 
    }
}