#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
typedef long long lint;

int main() {
	int H, W, N;
	cin >> H >> W >> N;
	
	typedef pair< int, int > pii;
	map< pii, int > cnt;
	for_(i,0,N) {
		int a, b;
		cin >> a >> b;
		for_(y,-2,1) for_(x,-2,1) {
			int yy = a + y, xx = b + x;
			if (yy < 1 || yy > H-2 || xx < 1 || xx > W-2) continue;
			cnt[pii(yy, xx)]++;
		}
	}
	
	vector< lint > ans(10, 0);
	for (auto x : cnt) ans[x.second]++;
	ans[0] = lint(H-2) * (W-2) - accumulate(ans.begin() + 1, ans.end(), lint());
	
	for_(i,0,10) cout << ans[i] << endl;
}
