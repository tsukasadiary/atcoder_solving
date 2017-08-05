#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
typedef long long lint;
template< typename T > using Vec = vector< T >;

struct Edge {int to, c; };

Vec< bool > checkVisible(int N, Vec< Vec< int > >& rev) {
	queue< int > que;
	que.push(N-1);
	
	Vec< bool > vis(N, false);
	vis[N-1] = true;
	
	while (!que.empty()) {
		int v = que.front(); que.pop();
		for (int u : rev[v]) {
			if (vis[u]) continue;
			que.push(u);
			vis[u] = true;
		}
	}
	
	return vis;
}

void solve(int N, Vec< Vec< Edge > >& edges, Vec< Vec< int > >& rev) {
	Vec< bool > vis = checkVisible(N, rev);
	Vec< lint > cst(N, -(1LL << 60));
	cst[0] = 0;
	
	bool inf = false;
	for_(rep,0,N+1) {
		for_(v,0,N) if (vis[v]) for (Edge& e : edges[v]) {
			if (vis[e.to] && cst[e.to] < cst[v] + e.c) {
				cst[e.to] = cst[v] + e.c;
				if (rep == N) inf = true;
			}
		}
	}
	
	if (inf) puts("inf");
	else cout << cst[N-1] << endl;
}

int main() {
	int N, M;
	cin >> N >> M;
	
	Vec< Vec< Edge > > edges(N);
	Vec< Vec< int > > rev(N);
	
	for_(i,0,M) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		edges[a].push_back(Edge{b, c});
		rev[b].push_back(a);
	}
	
	solve(N, edges, rev);
}
