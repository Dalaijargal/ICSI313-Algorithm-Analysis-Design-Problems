#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

int main() {
  int n;
  cin >> n;
  int input[n][n];
  int dp[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> input[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    dp[0][i] = input[0][i];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = dp[i - 1][j] + input[i][j];
      if (j > 0) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + input[i][j]);
      }
      if (j < n - 1) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + input[i][j]);
      }
    }
  }
  //   print dp
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  int result = INT_MAX;
  for (int i = 0; i < n; i++) {
    result = min(result, dp[n - 1][i]);
  }
  cout << result;
  return 0;
}