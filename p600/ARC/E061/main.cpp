#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
typedef long long lint;
template< typename T > using Vec = vector< T >;

lint encode(lint v, lint c) { return (v << 32) | c; }

struct Edge { lint to; int dst; };

int N, M;
unordered_map< lint, Vec< Edge > > edges;
unordered_map< lint, int > dst;

void solve() {
	deque< lint > que;
	que.push_back(0);
	dst[0] = 0;
	
	while (!que.empty()) {
		lint cur = que.front(); que.pop_front();
				
		for (const Edge& e : edges[cur]) {
			if (dst.count(e.to) == 0 || dst[e.to] > dst[cur] + e.dst) {
				dst[e.to] = dst[cur] + e.dst;
				if (e.dst == 0) que.push_front(e.to);
				else que.push_back(e.to);
			}
		}
	}
	
	if (dst.count(encode(N-1, 0)) == 0) puts("-1");
	else cout << dst[encode(N-1, 0)] << endl;
}

int main() {
	cin >> N >> M;
	
	for_(i,0,M) {
		int u, v, c;
		cin >> u >> v >> c;
		--u; --v;
		
		edges[encode(u, c)].push_back(Edge{encode(v, c), 0});
		edges[encode(v, c)].push_back(Edge{encode(u, c), 0});
		
		edges[encode(u, 0)].push_back(Edge{encode(u, c), 1});
		edges[encode(v, 0)].push_back(Edge{encode(v, c), 1});
		
		edges[encode(u, c)].push_back(Edge{encode(u, 0), 0});
		edges[encode(v, c)].push_back(Edge{encode(v, 0), 0});
	}
	
	solve();
}
