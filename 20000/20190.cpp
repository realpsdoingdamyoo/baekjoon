#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n;
int v[303030];

const int X=20;
int seg[1<<X+1];
void update(int p, int x) {
	p+=1<<X;
	while (p) seg[p]+=x, p>>=1;
}
int sum(int s, int e) {
	s+=1<<X; e+=1<<X; int r=0;
	while (s<=e) {
		if (s&1) r+=seg[s]; ++s>>=1;
		if (~e&1) r+=seg[e]; --e>>=1;
	} return r;
}

int pf[303030], sf[303030];

array<int, 3> gsg[1<<X+1];
array<int, 3> mrg(array<int, 3> a, array<int, 3> b) {
	array<int, 3> ret={};
	ret[0]=a[0]+b[0]; ret[1]=a[1]+b[1];
	ret[2]=min(min(a[2]+b[1], a[0]+b[2]), a[0]+b[1]);
	return ret;
}

void gupdate(int p, int t, int x) {
	p+=1<<X; gsg[p][t]+=x; gsg[p][2]=min(gsg[p][0], gsg[p][1]); p>>=1;
	while (p) gsg[p]=mrg(gsg[p<<1], gsg[p<<1|1]), p>>=1;
}

int dmi[303030];

signed main() {
	fastio;

	cin >> n;
	for (int i=1; i<=n; i++) cin >> v[i];

	int inv=0;
	for (int i=1; i<=n; i++) {
		inv+=sum(v[i]+1, 1010101);
		update(v[i], 1);
	}
	for (int i=1; i<(1<<X+1); i++) seg[i]=0;

	for (int i=1; i<=n; i++) dmi[i]=inv;

	for (int i=1; i<=n; i++) {
		dmi[i]-=sum(v[i]+1, 1010101);
		update(v[i], 1);
	}
	for (int i=1; i<(1<<X+1); i++) seg[i]=0;

	for (int i=n; i>=1; i--) {
		dmi[i]-=sum(1, v[i]-1);
		update(v[i], 1);
	}
	for (int i=1; i<(1<<X+1); i++) seg[i]=0;

	for (int i=1; i<=n; i++) gupdate(v[i]+1, 0, 1);

	for (int i=1; i<=n; i++) {
		gupdate(v[i]+1, 0, -1);
		cout << dmi[i]+gsg[1][2] << " ";
		gupdate(v[i], 1, 1);
	}


	return 0;
}
