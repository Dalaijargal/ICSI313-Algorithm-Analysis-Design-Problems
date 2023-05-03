#include <bits/stdc++.h>
using namespace std;
int dp[100000], e[100000], a[100000];
int max(int a, int b)
{
    return a > b ? a : b;
}
main()
{
    int n;
    cout << "n:";
    cin >> n;

    cout << "a[i]\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "\n e[i]\n";
    for (int i = 0; i < n; i++)
    {
        cin >> e[i];
    }

    dp[0] = a[0];
    dp[1] = e[0] + a[1];
    dp[2] = e[0] + e[1] + a[2];
    for (int i = 3; i < n; i++)
    {
        dp[i] = std::max(e[i] + dp[i - 1], a[i] + e[i - 1] + e[i - 2] + dp[i - 3]);
    }
    cout << "Erdeniin awch boloh onoo:" << dp[n - 1];
}