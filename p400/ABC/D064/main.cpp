#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)

int main() {
	int N;
	cin >> N;
	
	string S;
	cin >> S;
	
	int cnt_x = 0, x = 0, cnt_y = 0, y = 0;
	for_(i,0,N) {
		cnt_x += (S[i] == '(' ? -1 : 1);
		cnt_y += (S[N - i -1] == ')' ? -1 : 1);
		x = max(x, cnt_x);
		y = max(y, cnt_y);
	}
	
	cout << string(x, '(') << S << string(y, ')') << endl;
}
