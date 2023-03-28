#include<bits/stdc++.h>

using namespace std;

struct Baraa {
	int weight;
	int cost;
};

int main() {
	int n, w;
	cin >> n >> w;
	struct Baraa baraa[10000];
	int dp[n+1][w+1];
	
	memset(dp, 0, sizeof dp); // husnegtee 0-eer duurgene.
	
	for(int i=1; i<=n; i++)
		cin >> baraa[i].weight >> baraa[i].cost;
	
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=w; k++) {
//			if(k < baraa[i].weight)
				dp[i][k] = dp[i-1][k];
//			else
			if(k >= baraa[i].weight)
				dp[i][k] = max(dp[i][k], dp[i-1][k-baraa[i].weight] + baraa[i].cost);
		}
	}
	cout << "Hariu: " << dp[n][w];
}
