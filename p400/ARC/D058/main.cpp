#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long lint;
template<typename T > void modMul(T& a, T b, T m) { a = (a*b)%m; }
template<typename T > void modAdd(T& a, T b, T m) { a = (a+b)%m; }

const lint MOD = (lint)1e9 + 7;

lint power(lint x, int k) {
	lint res = 1;
	while (k) {
		if (k & 1) modMul(res, x, MOD);
		modMul(x, x, MOD);
		k >>= 1;
	}
	return res;
}

int main() {
	int H, W, A, B;
	cin >> H >> W >> A >> B;
	
	int S = H+W+10;
	vector< lint > fact(S, 0);
	fact[0] = fact[1] = 1;
	for_(i,2,S) fact[i] = (fact[i-1] * i) % MOD;
	
	vector< lint > inv(S, 0);
	for_(i,0,S) inv[i] = power(fact[i], MOD-2);
	
	auto nCk = [&](int n, int k) {
		lint res = fact[n];
		modMul(res, inv[n-k], MOD);
		modMul(res, inv[k], MOD);
		return res;
	};
	
	lint ans = 0;
	for_(i,B,W) {
		lint add = nCk(H-A-1+i, i);
		modMul(add, nCk(A-1+W-1-i, W-1-i), MOD);
		modAdd(ans, add, MOD);
	}
	cout << ans << endl;
}
