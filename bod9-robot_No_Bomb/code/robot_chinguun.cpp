#include <bits/stdc++.h>
using namespace std;

int x[2] = {-1, 0};
int y[2] = {0, 1};
// we have one bomb that can break the wall
// find the maxmimum gold that we can get
// 0: empty, -1: wall, 1: gold
int n;
int gg[1005][1005][2];
int dp(int usd, int i, int j, int n, vector <int> a[]){
    if(i == 0 && j == n - 1){
        return a[i][j];
    }
    if(gg[i][j][usd] != -1){
        return gg[i][j][usd];
    }
    int ans = 0;
    bool b = false;
    for(int k = 0; k < 2; k ++){
        int ii = i + x[k];
        int jj = j + y[k];
        if(ii >= 0 && ii < n && jj >= 0 && jj < n){
            if(a[ii][jj] != -1){
                b = true;
                ans = max(ans, dp(usd, ii, jj, n, a) + a[ii][jj]);
            }
            else if(a[ii][jj] == -1 && usd == 0){
                b = true;
                ans = max(ans, dp(1, ii, jj, n, a));
            }
        }
    }
    if(b == false){
        ans = -1e9;
    }
    gg[i][j][usd] = ans;
    return ans;

}

int main(){
    cin >> n;
    vector <int> a[n];
    memset(gg, -1, sizeof(gg));
    for(int i = 0; i < n; i ++){
        a[i].resize(n);
        for(int j = 0; j < n; j ++){
            cin >> a[i][j];
        }
    }
    cout << dp(0, n - 1, 0, n, a) << endl;
    return 0;
}