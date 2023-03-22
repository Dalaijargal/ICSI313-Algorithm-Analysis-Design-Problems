#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

struct product {
  int coin;
  int price;
};

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  struct product products[m - 1];
  for (int i = 1; i <= m; i++) {
    struct product temp;
    cin >> temp.coin >> temp.price;
    products[i] = temp;
  }
  int dp[m + 1][n + 1];
  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (j - products[i].coin >= 0) {
        dp[i][j] = max(dp[i - 1][j - products[i].coin] + products[i].price,
                       dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  cout << dp[m][n];
  return 0;
}