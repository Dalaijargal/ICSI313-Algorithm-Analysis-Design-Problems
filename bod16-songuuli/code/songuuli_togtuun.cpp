#include<bits/stdc++.h>

using namespace std;

int dp[1000001];
int active[1000001];
int inactive[1000001];

bool inBounds(int i, int n) {
  if (i >= 0 && i < n) return true;
  return false;
}

int main() {
  int n;
  cin >> n;
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < n; i++) cin >> active[i];
  for (int i = 0; i < n; i++) cin >> inactive[i];

  dp[0] = max(active[0], inactive[0]);
  dp[1] = max(active[0] + inactive[1], active[1] + inactive[0]);
  dp[2] = max(active[2] + inactive[1] + inactive[0], max(active[1] + inactive[2] + inactive[0], active[0] + inactive[1] + inactive[2]));
  for (int i = 3; i < n; i++) {
    dp[i] = max(dp[i - 1] + inactive[i], dp[i - 3] + active[i] + inactive[i - 1] + inactive[i - 2]);
  }
  // for (int i = 0; i < n; i++) {
  //   cout << dp[i] << " ";
  // }
  cout << dp[n - 1];
}