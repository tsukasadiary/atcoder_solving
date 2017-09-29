#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
typedef long long lint;

int main() {
	string S;
	cin >> S;
	
	vector< lint > cnt(26, 0);
	for (char c : S) cnt[c-'a']++;
	
	lint n = S.size(), sub = 0;
	for_(i,0,26) sub += cnt[i]*(cnt[i]-1)/2;
	
	cout << n*(n-1)/2 - sub + 1 << endl;
}
