#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, k;
    cin >> n;
    int a[n][n], dp[n][n];

    memset(dp, 0, sizeof(dp));

    for(int i=0; i<n; i++) {
        for(int k=0; k<n; k++) {
            cin >> a[i][k];
            dp[i][k] = a[i][k];
        }
    }

    i = 0; k = n-1;
    while(!(i == n-1 && k == 0)) {
        if((a[i][k-1] == -1 || k == 0) && a[i+1][k] > -1 && i+1 < n) {
            dp[i+1][k] = dp[i][k] + a[i+1][k];
            i++;
        }
        else if((a[i+1][k] == -1 || i == n-1) && a[i][k-1] > -1 && k-1 >= 0) {
            dp[i][k-1] = dp[i][k] + a[i][k-1];
            k--;
        }
        else if(a[i+1][k] > -1 && a[i][k-1] > -1 && i+1 < n && k-1 >= 0) {
            if(a[i][k-1] > a[i+1][k]){
                dp[i][k-1] = dp[i][k] + a[i][k-1];
                k--;
            }
            else {
                dp[i+1][k] = dp[i][k] + a[i+1][k];
                i++;
            }
        }
        else {
            a[i][k] = -1;
            dp[i][k] = -1;
            i = 0;
            k = n-1;
        }
    }

    for(int i=0; i<n; i++) {
        for(int k=0; k<n; k++) {
            cout << dp[i][k] << "\t";
        }
        cout << endl;
    }
    cout << endl << dp[n-1][0] << endl;
}

// Tsogbadrakh_test01.in test deer unaj baina. Busad buh oyutnii test deer ajillaj baigaa.