#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> &matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
  cout << "------------------" << endl;
}

int main() {
  int n = 5;
  int A[5][5] = {
      {0, -1, 0, 0, 0}, {0, 0, 1, -1, 0}, {1, 1, 0, -1, -1},
      {0, 0, 0, 1, 1},  {0, 0, 0, -1, 1},
  };

  //   bodolt
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < n + 1; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = n - 1; j >= 0; j--) {
      if (A[i][j] == -1) {
        dp[i][j] = -1;
        continue;
      }
      dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]) + A[i - 1][j];
      // dp[i][j]=i*10+j;
    }
    // breakpoint
    printMatrix(dp);
  }
  cout << dp[n][0] << endl;
  return 0;
}