#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define for_rev(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long lint;

int N;
lint L, a[100005];

int main() {
	cin >> N >> L;
	for_(i,0,N) cin >> a[i];
	
	int s = -1;
	for_(i,0,N-1) if (a[i] + a[i+1] >= L) { s = i; break; }
	
	if (s == -1) return !printf("Impossible\n");
	puts("Possible");
	for_(i,0,s) cout << i+1 << endl;
	for_rev(i,N-2,s) cout << i+1 << endl;
}
