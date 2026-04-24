#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int n, s;

const int X=17;
array<int, 3> seg[1<<X+1];

array<int, 3> mrg(array<int, 3> a, array<int, 3> b) {
	return {max(max(a[0], b[0]), b[2]-a[1]), min(a[1], b[1]), max(a[2], b[2])};
}

void update(int p, int x) {
	seg[p+(1<<X)]={-inf, x, x}; p=(p+(1<<X))>>1;
	while (p) seg[p]=mrg(seg[p<<1], seg[p<<1|1]), p>>=1;
}

array<int, 3> gold(int s, int e) {
	array<int, 3> ret={-inf, inf, -inf};
	s+=1<<X; e+=1<<X;
	for (int i=X; i>=0; i--) {
		int S=(s-1>>i)+1, E=(e+1>>i)-1;
		if (S>E) continue;
		if (S&1) ret=mrg(seg[S], ret);
		if (~E&1) ret=mrg(ret, seg[E]);
	}
	return ret;
}


signed main() {
	fastio;

	cin >> n;
	for (int i=1; i<=n; i++) {
		int a; cin >> a; s+=a;
		update(i, s);
	}

	int q; cin >> q;
	for (int i=1; i<=q; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--; b--;

		int ret=-inf;
		ret=max(ret, gold(c, b)[0]);
		ret=max(ret, gold(c, d)[2]-gold(a, min(b, c-1))[1]);
		ret=max(ret, gold(max(b+1, c), d)[2]-gold(a, b)[1]);
		cout << ret << "\n";
	}

	return 0;
}
