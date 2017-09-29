#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
typedef long long lint;

int N, A[100005];
vector< vector< int > > adj;

void yes() { puts("YES"); exit(0); }
void no() { puts("NO"); exit(0); }

lint rec(int v, int p) {
	if (adj[v].size() == 1) return A[v];
	
	vector< lint > deg;
	for (int u : adj[v]) if (u != p) deg.push_back(rec(u, v));
	lint sum = accumulate(deg.begin(), deg.end(), lint());
	
	if (p == -1 && 2 * A[v] != sum) no();
	if (2 * A[v] - sum < 0) no();
	deg.push_back(2 * A[v] - sum);
	for (lint x : deg) if (A[v] < x) no();
	return deg.back();
}

int main() {
	cin >> N;
	for_(i,0,N) cin >> A[i];
	
	adj.assign(N, vector< int >());
	for_(i,0,N-1) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for_(v,0,N) {
		if (adj[v].size() > 1) {
			rec(v, -1);
			yes();
		}
	}
	
	if (A[0] == A[1]) yes();
	no();
}
