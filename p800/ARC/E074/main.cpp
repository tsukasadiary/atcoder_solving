#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
typedef pair< int, int > pii;
template< typename T > using Vec = vector< T >;

int N, M, dp[301][301][301];
Vec< pii > seg[301];

const int MOD = (int)1e9 + 7;
void updateDP(int &a, int b) {
	if (a == -1 || b == -1) return;
	a = (a + b) % MOD;
}

bool validate(int r, int g, int b) {
	for (pii p : seg[r]) {
		int cnt = 1 + (p.first <= g) + (p.first <= b);
		if (p.second != cnt) return false;
	}
	return true;
}

int main() {
	cin >> N >> M;
	for_(i,0,M) {
		int l, r, x;
		cin >> l >> r >> x;
		seg[r].push_back(pii(l, x));
	}
	
	memset(dp, 0, sizeof(dp));
	for_(mx,0,N+1) for_(a,0,mx) for_(b,0,mx) {
		if (!validate(mx, a, b)) {
			dp[mx][a][b] = -1;
			dp[a][mx][b] = -1;
			dp[a][b][mx] = -1;
		}
	}
	
	dp[0][0][0] = 1;
	for_(r,0,N) for_(g,0,N) for_(b,0,N) {
		int k = max(r, max(g, b)), num = dp[r][g][b];
		updateDP(dp[k+1][g][b], num);
		updateDP(dp[r][k+1][b], num);
		updateDP(dp[r][g][k+1], num);
	}
	
	int ans = 0;
	for_(i,0,N) for_(j,0,N) {
		updateDP(ans, dp[N][i][j]);
		updateDP(ans, dp[i][N][j]);
		updateDP(ans, dp[i][j][N]);
	}
	
	cout << ans << endl;
}
