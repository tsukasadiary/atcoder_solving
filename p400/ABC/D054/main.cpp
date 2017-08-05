#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
template< typename T > using Vec = vector< T >;

int N, Ma, Mb, dp[41][401][401];

void update(int& a, int b) {
	if (a == -1) a = b;
	else a = min(a, b);
}

int main() {
	cin >> N >> Ma >> Mb;
	
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	
	for_(i,0,N) {
		int a, b, c;
		cin >> a >> b >> c;
		
		for_(x,0,401) for_(y,0,401) {
			if (dp[i][x][y] == -1) continue;
			update(dp[i+1][x][y], dp[i][x][y]);
			update(dp[i+1][x+a][y+b], dp[i][x][y] + c);
		}
	}
	
	int ans = -1;
	for_(r,1,400) {
		if (r * Ma > 400 || r * Mb > 400) break;
		if (dp[N][r*Ma][r*Mb] > 0) update(ans, dp[N][r*Ma][r*Mb]);
	}
	cout << ans << endl;
}
