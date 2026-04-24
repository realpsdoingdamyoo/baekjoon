#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int n, k, q;
int v[252525];

const int X=18;
int seg[1<<X+1];

void update(int p, int t) {
	p+=1<<X;
	while (p) seg[p]+=t, p>>=1;
}
int sum(int s, int e) {
	int r=0; s+=1<<X; e+=1<<X;
	while (s<=e) {
		if (s&1) r+=seg[s]; ++s>>=1;
		if (~e&1) r+=seg[e]; --e>>=1;
	}
	return r;
}

int sg[1<<X+1];

void Update1(int p, int x) {
	if (p>=(1<<X)) {
		update(p-(1<<X), -(sg[p]==k));
		sg[p]|=x;
		update(p-(1<<X), (sg[p]==k));
		p>>=1;
		while (p) sg[p]=sg[p<<1]&sg[p<<1|1], p>>=1;
		return;
	}
	if ((sg[p]&x)!=x) Update1(p<<1, x), Update1(p<<1|1, x), sg[p]=sg[p<<1]&sg[p<<1|1];
}

void Update(int s, int e, int x) {
	s+=1<<X; e+=1<<X;
	while (s<=e) {
		if ((s&1) && (sg[s]&x)!=x) Update1(s, x); ++s>>=1;
		if ((~e&1) && (sg[e]&x)!=x) Update1(e, x); --e>>=1;
	}
}

signed main() {
	fastio;

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> v[i];
		Update(i, i, v[i]);
		update(i, (v[i]==k)-sum(i, i));
	}

	cin >> q;
	for (int i=1; i<=q; i++) {
		int a, b, c, d; cin >> a;
		if (a==1) {
			cin >> b >> c >> d;
			Update(b, c, d);
		}
		else {
			cin >> b >> c;
			cout << sum(b, c) << "\n";
		}
	}


	return 0;
}
