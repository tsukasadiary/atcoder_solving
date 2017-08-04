#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define allof(a) (a).begin(),(a).end()
template< typename T > using Vec = vector< T >;
template< typename T > void minUpdate(T& a, T b) { a = min(a, b); }

int main() {
	int N, M;
	cin >> N >> M;
	
	struct Edge { int u, v, c; };
	Vec< Edge > edges;
	
	Vec< Vec< int > > dst(N, Vec< int >(N, 1L << 28));
	for_(i,0,N) dst[i][i] = 0;
	
	for_(i,0,M) {
		int u, v, c;
		cin >> u >> v >> c;
		--u; --v;
		
		edges.push_back(Edge{u, v, c});
		dst[u][v] = dst[v][u] = c;
	}
	
	for_(k,0,N) for_(i,0,N) for_(j,0,N) minUpdate(dst[i][j], dst[i][k] + dst[k][j]);
	
	int ans = 0;
	for (Edge& e : edges) if (dst[e.u][e.v] < e.c) ++ans;
	cout << ans << endl;
}
