#include <iostream>
#include <vector>
using namespace std;

struct Item {
  int weight;
  int value;
};

int main() {
  int n, w;
  cin >> n >> w;
  Item items[n];
  for (int i = 0; i < n; i++) {
    cin >> items[i].weight >> items[i].value;
  }
  // bodolt
  int dp[n + 1][w + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= w; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (items[i - 1].weight <= j) {
        dp[i][j] = max(dp[i - 1][j],
                       dp[i - 1][j - items[i - 1].weight] + items[i - 1].value);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  cout << dp[n][w] << endl;

  vector<int> bag;
  int i = n, j = w;
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else {
      bag.push_back(i);
      j -= items[i - 1].weight;
      i--;
    }
  }
  cout << bag.size() << endl;
  for (int i = bag.size() - 1; i >= 0; i--) {
    cout << bag[i] << " ";
  }
  cout << endl;

  return 0;
}