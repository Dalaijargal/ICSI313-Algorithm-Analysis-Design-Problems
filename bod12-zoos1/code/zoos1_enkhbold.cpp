#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
int n, m;
vector<int> c, dp;

int main() {

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        c.push_back(tmp);
    }

    sort(c.begin(), c.end());


    //BASE
    for (int i = 0; i < c[0]; i++) {
        if(i == c[0] - 1) {
            dp.push_back(1);
            break;
        }
        dp.push_back(0);
    }


    // RELATION
    for (int i = c[0]; i < n; i++) {
        vector<int> tmpList;
        for (int j = 0; j < m; j++) {
            if(i - c[j] >= 0)
                tmpList.push_back(dp[i - c[j]]);
        }

        dp.push_back(*min_element(tmpList.begin(), tmpList.end()) + 1);
    }

    cout << dp[n - 1];
}