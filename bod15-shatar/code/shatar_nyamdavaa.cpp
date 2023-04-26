#include<bits/stdc++.h>
using namespace std ;

int main () {
    int n ; cin >> n ; 
    int a[n][n], dp[n][n] ; 
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j ++) cin >> a[i][j] ; 
    }
    
    for (int j = 0 ; j < n ; j ++) {
        dp[0][j] = a[0][j] ; 
    }
    for (int i = 1 ; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++) {
            dp[i][j] = dp[i-1][j] ; 
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]) ; 
            }
            if (j < n-1) {
                dp[i][j] = min(dp[i][j], dp[i-1][j+1]) ; 
            }
            dp[i][j] += a[i][j] ;
        }
    }
    int ans = INT_MAX ; 
    for (int j = 0 ; j < n ; j ++) {
        ans = min(ans, dp[n-1][j]) ;
    }
    cout << ans << "\n" ; 
}