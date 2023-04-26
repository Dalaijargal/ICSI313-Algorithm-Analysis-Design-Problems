#include<bits/stdc++.h>

using namespace std;

int dp[10001][10001];
int energies[10001][10001];

bool inBounds(int i, int n) {
  if (i >= 0 && i < n) return true;
  return false;
}

int main() {
  int n;
  cin >> n;
  memset(dp, INT_MAX, sizeof dp);
  for (int i = 0; i < n; i++) {
    dp[0][i] = 0;
    energies[0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> energies[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      int minValue = INT_MAX;
      if (inBounds(i - 1, n) && inBounds(j - 1, n))
        minValue = min(dp[i - 1][j - 1] + energies[i][j], minValue);
      if (inBounds(i - 1, n) && inBounds(j, n))
        minValue = min(dp[i - 1][j] + energies[i][j], minValue);
      if (inBounds(i - 1, n) && inBounds(j + 1, n))
        minValue = min(dp[i - 1][j + 1] + energies[i][j], minValue);
      dp[i][j] = minValue;
    }
  }
  int minValue = INT_MAX;
  for (int i = 0; i < n; i++)
    minValue = min(minValue, dp[n][i]);
  cout << minValue;
}