#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, tooluur = 0;
	cout << "n= ";
	cin >> n;
	cout << "m= ";
	cin >> m;
	int c[m];
	for(int i=0; i<m; i++) {
		cin >> c[i];
	}
	
	for(int i=0; i<m; i++) {
		for(int k=0; k<m; k++) {
			for(int j=0; j<m; j++) {
				if(c[i]+c[k]+c[j] == n) {
					tooluur++;
				}
			}
		}
	}
	cout << "Hariu: " << tooluur;
}
