#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
template< typename T > void modAdd(T& a, T b, T m) { a = (a+b+m)%m; }
typedef long long lint;

int N, X, Y, Z;
lint dp[41][1<<18];
const lint MOD = (lint)1e9 + 7;

int main() {
	cin >> N >> X >> Y >> Z;
	
	int MASK = (1 << (X+Y+Z+1)) - 1, valid = (1 << Z) | (1 << (Y+Z)) | (1 << (X+Y+Z));
	
	memset(dp, 0, sizeof(dp));
	dp[0][1] = 1;
	
	for_(i,0,N) for_(S,0,MASK+1) {
		for_(x,1,11) {
			int nxt = ((S << x) | 1) & MASK;
			if ((nxt & valid) == valid) continue;
			modAdd(dp[i+1][nxt], dp[i][S], MOD);
		}
	}
	
	lint ans = 1;
	for_(i,0,N) ans *= 10, ans %= MOD;
	for_(S,0,MASK) modAdd(ans, -dp[N][S], MOD);
	cout << ans << endl;
}
