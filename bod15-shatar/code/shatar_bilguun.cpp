#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n][n], dp[n][n];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }
    
    memset(dp, 0, sizeof(dp));

    for(int i=0; i<n; i++) {
        dp[0][i] = A[0][i];
    }

    for(int i=1; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(j == 0) {
                dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
            }
            else if(j == n - 1) {
                dp[i][j] = A[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
            }
            else {
                dp[i][j] = A[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
            }
        }
    }
    cout << "---------------------" << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
    int min = 9999;
    for(int j=0; j<n; j++) {
        if(min > dp[n-1][j]) {
            min = dp[n-1][j];
        }
    }
    cout << min;
}