#include<bits/stdc++.h>
using namespace std ;
#define pii pair<int,int>
#define dbg(x) cout << #x << ": " << x << " " ; 
#define ell cout << "\n" ; 

bool cmp (pair<pii, int> p1, pair<pii, int> p2) {
    return p1.first.second < p2.first.second ; 
}

int main () {
    int n ; cin >> n ; 
    pair<pair<int,int>, int> a[n] ; 
    int dp[n] ;
    memset(dp, 0, sizeof dp) ; 
    for (int i = 0 ; i < n ; i ++) {    
        cin >> a[i].first.first >> a[i].first.second >> a[i].second ; 
    }

    sort(a, a+n, cmp) ;
    
    dp[0] = a[0].second ; 
    for (int i = 1 ; i < n ; i ++) { 
        int st = a[i].first.first ; 
        // l ba r ni haih range-iin zuun ba baruun hyzgaar 
        int l = 0, r = i - 1 ; 
        while (l < r) {
            int m = (l + r + 1) / 2 ;
            if (a[m].first.second < st) {
                l = m ; 
            } else {
                r = m - 1 ; 
            }
        }

        if (a[l].second < st) {
            dp[i] = max(dp[i-1], dp[l] + a[i].second) ; 
        } else {
            dp[i] = max(dp[i-1], a[i].second) ; 
        }
    }
    cout << dp[n-1] << "\n" ; 
}