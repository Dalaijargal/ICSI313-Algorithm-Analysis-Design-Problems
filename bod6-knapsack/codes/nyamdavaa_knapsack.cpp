#include<bits/stdc++.h>
using namespace std ;
#define pii pair<int,int>

int main () {
    int n ; cin >> n ;
    int w ; cin >> w ;  
    // first is value, second is weight 
    pii items[n + 1] ; 
    for (int i = 1 ; i <= n ; i ++) cin >> items[i].first >> items[i].second ;  
    int dp[n+1][w+1] ; 
    memset(dp, 0, sizeof dp) ; 
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= w ; j ++) {
            dp[i][j] = dp[i-1][j] ; 
            if (j >= items[i].second) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-items[i].second] + items[i].first) ; 
            }
        }
    }
    cout << dp[n][w] << "\n" ; 
}