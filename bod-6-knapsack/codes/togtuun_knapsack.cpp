#include<bits/stdc++.h>
using namespace std;


int main () {
  int n, W;
  cin >> n >> W;
  int weights[n];
  int values[n];

  pair<int,int> dp[n + 1][W + 1];
  memset(dp, {0, 0}, sizeof dp);

  for (int i = 1; i <= n; i ++) {
    int sum = 0;
    for (int o = 1; o <= W; o ++) {
      // cout << dp[i][o];
      if (dp[i-1][o].second + weights[o] <= W) {
        if(o - weights[o] > 0) {
          dp[i][o].first = dp[i - 1][o - weights[o]].first + values[o];
          dp[i][o].second = dp[i - 1][o - weights[o]].second + weights[o];
        } else {
          
        }
      } else {
        dp[i][o].first = dp[i - 1][o].first + values[o];
        dp[i][o].second = dp[i - 1][o].second + weights[o];
      }
    }
    // cout << endl;
  }

  cout << dp[n][W].first;
}