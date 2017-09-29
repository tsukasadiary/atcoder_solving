#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
typedef long long lint;

int N, a[200005], b[200005];

int main() {
	cin >> N;
	for_(i,0,N) {
		cin >> a[i];
		b[a[i]] = i;
	}
	
	lint ans = 0;
	set< lint > index = {-1,N};
	for_(i,1,N+1) {
		auto R = index.upper_bound(b[i]);
		auto L = R; --L;
		index.insert(b[i]);
		ans += ((*R) - b[i]) * (b[i] - (*L)) * i;
	}
	cout << ans << endl;
}
