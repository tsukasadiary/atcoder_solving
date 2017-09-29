#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)

int main() {
	int N, K;
	cin >> N >> K;
	
	vector< int > A(N);
	for_(i,0,N) cin >> A[i];
	sort(A.begin(), A.end());
	
	int g = A[0];
	for_(i,1,N) g = __gcd(g, A[i]);
	
	puts(K <= A[N-1] && K % g == 0 ? "POSSIBLE" : "IMPOSSIBLE");
}
