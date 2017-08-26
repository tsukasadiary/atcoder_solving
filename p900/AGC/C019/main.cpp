//------------------------------>> tsukasa_diary's template <<------------------------------//
#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define for_rev(i,a,b) for(int i=(a);i>=(b);--i)
#define allof(a) (a).begin(),(a).end()
#define minit(a,b) memset(a,b,sizeof(a))

using lint = long long;
using pii = pair< int, int >;

template< typename T > using Vec = vector< T >;

template< typename T > bool in_range(T x, T lb, T ub) { return lb <= x && x < ub; }
template< typename T > bool in_range(T x, T y, T lb, T ub) { return in_range(x, lb, ub) && in_range(y, lb, ub); }

template< typename T > void modAdd(T& a, T b, T mod) { a = (a + b) % mod; }
template< typename T > void modMul(T& a, T b, T mod) { a = (a * b) % mod; }
template< typename T > void minUpdate(T& a, T b) { a = min(a, b); }
template< typename T > void maxUpdate(T& a, T b) { a = max(a, b); }

int bitCount(int x) { return __builtin_popcount(x); }
int bitCount(lint x) { return __builtin_popcountll(x); }

const int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
const int Dx[8] = {0,1,1,1,0,-1,-1,-1}, Dy[8] = {-1,-1,0,1,1,1,0,-1};
//------------------------------>> coding space <<------------------------------//

template< typename DATA, class CALC, DATA FAIL >
class SegmentTree {
private:
	int size__;
	Vec< DATA > data;
	
	inline int left_t(int k) { return (k << 1) + 1; }
	inline int right_t(int k) { return (k << 1) + 2; }
	inline int center(int l, int r) { return (l + r) >> 1; }
	
	DATA calc(DATA d1, DATA d2) { return CALC().calc(d1, d2); }
	
	DATA query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return FAIL;
		if (a <= l && r <= b) return data[k];
		return calc(query(a, b, left_t(k), l, center(l, r)),
					query(a, b, right_t(k), center(l, r), r));
	}
	
public:
	SegmentTree(int n, DATA ini) {
		for (size__ = 1; size__ < n; size__ <<= 1);
		data.assign(2 * size__ - 1, ini);
	}
	
	void update(int k, DATA a) {
		k += size__ - 1;
		data[k] = a;
		
		while (k > 0) {
			k = (k - 1) >> 1;
			data[k] = calc(data[left_t(k)], data[right_t(k)]);
		}
	}
	
	DATA query(int a, int b) { return query(a, b, 0, 0, size__); }
	
	int size() { return size__; }
};

template< typename T >
class MaxCalc {
public:
	inline T calc(T d1, T d2) { return max(d1, d2); }
};



int x[2], y[2], N, X[200005], Y[200005];

const int MAX_Z = (int)(1e8)-1;

void reverseX() {
	for_(i,0,2) x[i] = MAX_Z - x[i];
	for_(i,0,N) X[i] = MAX_Z - X[i];
}

void reverseY() {
	for_(i,0,2) y[i] = MAX_Z - y[i];
	for_(i,0,N) Y[i] = MAX_Z - Y[i];
}

int main() {
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	cin >> N;
	for_(i,0,N) cin >> X[i] >> Y[i];
	
	if (x[0] > x[1]) reverseX();
	if (y[0] > y[1]) reverseY();
	
	Vec< int > use, yset, xset;
	for_(i,0,N) {
		if (in_range(X[i], x[0], x[1]+1) &&
			in_range(Y[i], y[0], y[1]+1)) {
			use.push_back(i);
			yset.push_back(Y[i]);
		}	
	}
	sort(allof(use), [&](int i, int j) { return X[i] < X[j]; });
	sort(allof(yset));
	
	int m = use.size();
	double pr = 0.5 * acos(-1) * 10, base = double(x[1] - x[0] + y[1] - y[0]) * 100;
	
	cout << setprecision(15) << setiosflags(ios::fixed);
	if (m == 0) {
		cout << base << endl;
		return 0;
	}
	
	SegmentTree< int, MaxCalc< int >, 0 > seg(m, 0);
	
	for_(ii,0,m) {
		int i = use[ii];
		int yi = lower_bound(allof(yset), Y[i]) - yset.begin();
		int add = seg.query(0, yi);
		seg.update(yi, add + 1);
	}
	
	int nc = seg.query(0, m);
	double add = 0;
	if (nc == min(x[1]-x[0], y[1]-y[0])+1) add = pr;
	cout << base - (20. - pr) * nc + add << endl;
}
