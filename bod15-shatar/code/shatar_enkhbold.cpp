#include <bits/stdc++.h>

using namespace std;

int main() {
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
            vector<int> tmpList;
            if(j - 1 >= 0)
                tmpList.push_back(dp[i - 1][j - 1]);
            if(j + 1 < n)
                tmpList.push_back(dp[i - 1][j + 1]);
            tmpList.push_back(dp[i - 1][j]);

            dp[i][j] = *min_element(tmpList.begin(), tmpList.end()) + a[i][j];
        }
    }

    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end());
}