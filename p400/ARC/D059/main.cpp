#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)

int main() {
	string S;
	cin >> S;
	
	int n = S.size();
	
	for_(x,1,3) for_(i,0,n-x) {
		if (S[i] == S[i + x]) {
			cout << i+1 << " " << i+x+1 << endl;
			exit(0);
		}
	}
	
	puts("-1 -1");
}
