#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
typedef long long lint;

int N, A, B;
lint dp[55][55], cnt[55][55];

int main() {
	cin >> N >> A >> B;
	
	memset(dp, 0, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));
	cnt[0][0] = 1;
	
	for_(i,0,N) {
		lint v; cin >> v;
		for_(j,0,i+1) {
			if (cnt[i][j] == 0) continue;
			
			for_(b,0,2) {
				lint &pre = dp[i+1][j+b], nxt = dp[i][j] + b * v, &pre_c = cnt[i+1][j+b];;
				if (pre <= nxt) {
					pre_c = (pre == nxt ? pre_c : 0) + cnt[i][j];
					pre = nxt;
				}
			}
		}
	}
	
	long double ans_v = 0;
	lint ans_c = 0;
	for_(i,A,B+1) {
		long double val = (long double)dp[N][i] / i;
		if (ans_v <= val) {
			ans_c = (ans_v == val ? ans_c : 0) + cnt[N][i];
			ans_v = val;
		}
	}
	printf("%.9Lf\n%Ld\n", ans_v, ans_c);
}
