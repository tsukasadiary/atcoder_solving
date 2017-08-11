#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define for_rev(i,a,b) for(int i=(a);i>=(b);--i)
#define allof(a) (a).begin(),(a).end()
typedef long long lint;
typedef pair< int, int > pii;
template< typename T > using Vec = vector< T >;

class SegmentTree {
private:
	int size__;
	Vec< int > data;
	
	inline int left_t(int k) { return (k << 1) + 1; }
	inline int right_t(int k) { return (k << 1) + 2; }
	inline int center(int l, int r) { return (l + r) >> 1; }
	
	int calc(int  d1, int  d2) { return min(d1, d2); }
	
	int query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return 1e9;
		if (a <= l && r <= b) return data[k];
		return calc(query(a, b, left_t(k), l, center(l, r)),
					query(a, b, right_t(k), center(l, r), r));
	}
	
public:
	SegmentTree() {}
	
	SegmentTree(int n) {
		for (size__ = 1; size__ < n; size__ <<= 1);
		data.assign(2 * size__ - 1, 1e9);
	}
	
	void update(int k, int  a) {
		k += size__ - 1;
		data[k] = a;
		
		while (k > 0) {
			k = (k - 1) >> 1;
			data[k] = calc(data[left_t(k)], data[right_t(k)]);
		}
	}
	
	int query(int a, int b) { return query(a, b, 0, 0, size__); }
};

int N, perm[200010];
SegmentTree seg[2];

Vec< pii > piece;
Vec< Vec< int > > nxt;
map< pii , int > piece_to_id;

void divide(int l, int r, int par) {
	if (l >= r) return;
	
	int a = seg[l % 2].query(l, r-1);
	int b = seg[(l + 1) % 2].query(perm[a]+1, r);
	
	if (par != -1) nxt[par].push_back(piece.size());
	piece_to_id[pii(a, b)] = piece.size();
	piece.push_back(pii(a, b));
	
	int cur = piece.size() - 1;
	nxt.push_back(Vec< int >());
	if (l < perm[a]) divide(l, perm[a], cur);
	divide(perm[a] + 1, perm[b], cur);
	if (perm[b] + 1 < r) divide(perm[b] + 1, r, cur);
}

int main() {
	cin >> N;
	
	for_(i,0,2) seg[i] = SegmentTree(N);
	
	for_(i,0,N) {
		int p; cin >> p;
		perm[p] = i;
		seg[i % 2].update(i, p);
	}
	
	divide(0, N, -1);
	
	Vec< int > ans;
	priority_queue< pii, Vec< pii >, greater< pii > > que;
	que.push(piece[0]);
	
	while (!que.empty()) {
		pii p = que.top(); que.pop();
		ans.push_back(p.first);
		ans.push_back(p.second);
		
		int id = piece_to_id[p];
		for (int i : nxt[id]) que.push(piece[i]);
	}
	
	for_(i,0,N) cout << ans[i] << (i < N - 1 ? " " : "\n");
}
