#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
typedef long long lint;

int N, K, A[100005];
lint B[100005];

int main() {
	cin >> N >> K;
	for_(i,0,N) cin >> A[i] >> B[i];
	
	lint ans = 0;
	for_(i,0,N) if ((A[i] & (~K)) == 0) ans += B[i];
	
	for_(i,0,31) {
		if (K >> i & 1) {
			int L = (K ^ (1 << i)) | ((1 << i) - 1);
			lint sum = 0;
			for_(i,0,N) if ((A[i] & (~L)) == 0) sum += B[i];
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
}
