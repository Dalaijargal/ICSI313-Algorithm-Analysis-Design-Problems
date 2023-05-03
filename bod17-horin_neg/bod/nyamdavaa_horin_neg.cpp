#include<bits/stdc++.h>
using namespace std ;
#define dbg(x) cout << #x << ": " << x << " " ; 

int main () {
    int n ; cin >> n ;
    int a[n+1] ; 
    for (int i = 1; i <= n ; i ++) cin >> a[i] ; 
    int dp[n+1][2] ; 
    memset(dp, -1, sizeof dp) ; 
    dp[0][0] = dp[0][1] = 0 ; 
    for (int i = 1 ; i <= n ; i ++) {
        if (i >= 4) {
            dp[i][0] = max(dp[i-4][0], dp[i-4][1]) ; 
            if (dp[i][0] != -1) {
                int secondPlayerScore = a[i] + a[i-1] ;
                int firstPlayerScore = a[i-2] + a[i-3] ; 
                if (secondPlayerScore > firstPlayerScore) {
                    dp[i][0] ++ ; 
                }
            }
            // else: round cant be finished 
        }
        if (i >= 5) {
            dp[i][1] = max(dp[i-5][0], dp[i-5][1]) ; 
            if (dp[i][1] != -1) {
                int secondPlayerScore = a[i] + a[i-1] + a[i-2] ; 
                int firstPlayerScore = a[i-3] + a[i-4] ; 
                if (secondPlayerScore < 21 && secondPlayerScore > firstPlayerScore) {
                    dp[i][1] ++ ; 
                }
            }            
            // else: round cant be finished 
        }
    }
    int ans = 0 ; 
    for (int i = 0 ; i <= n ; i ++) {
        ans = max(ans, max(dp[i][0], dp[i][1])) ; 
    }
    cout << ans << endl ;

}