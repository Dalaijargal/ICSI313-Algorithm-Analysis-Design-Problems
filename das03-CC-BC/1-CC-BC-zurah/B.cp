#include "bits/stdc++.h"
#define int long long
#define boost() ios_base :: sync_with_stdio(0); cin.tie(); cout.tie(); cout << fixed; cout << setprecision(15); srand(time(NULL))
using namespace std;

int equalize(vector<int> arr, int max_value) {
    int res = 0;
    multiset <int> ms;
    for (int i = 0; i < arr.size(); i++) ms.insert(arr[i]);
    while (*ms.begin() + 2 <= max_value) {
        int min_value = *ms.begin();
        ms.erase(ms.begin());
        ms.insert(min_value + 2);
        res++;
    }
    int cnt = 0;
    for (auto it : ms) if (it != max_value) cnt++;
    if (cnt & 1) return -1;
    return res + cnt / 2;
}

signed main() {
    int n, res = 0, max_value = 0; cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i], max_value = max(max_value, arr[i]);
    int res1 = equalize(arr, max_value);
    int res2 = equalize(arr, max_value + 1);
    // cout << res1 << " " << res2 << endl;
    if (res1 == -1 && res2 == -1) cout << -1 << endl;
    else if (res1 == -1) cout << res2 << endl;
    else if (res2 == -1) cout << res1 << endl;
    else cout << min(res1, res2) << endl;
    return 0;
}