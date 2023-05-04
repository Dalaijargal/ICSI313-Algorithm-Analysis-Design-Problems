#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;

    cin >> n;
    vector<vector<int>> a(n);
    vector<vector<int>> dp(n);


    for (int i = 0; i < n; i++) {
        a[i] = vector<int>(n);
        dp[i] = vector<int>(n);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    
    //BASE
    for (int i = 0; i < n; i++)
        dp[0][i] = a[0][i];


    //RELATION
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int left = __INT_MAX__;
            int mid = __INT_MAX__;
            int right = __INT_MAX__;

            if(j - 1 >= 0)
                left = dp[i - 1][j - 1];

            if(j + 1 < n)
                right = dp[i - 1][j + 1];
       
            mid = dp[i - 1][j];

            dp[i][j] = min(mid, min(left, right)) + a[i][j];
        }
    }

    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end());
}
