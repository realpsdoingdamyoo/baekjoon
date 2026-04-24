#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, t, a, b, p;
int v[505050];
vector<array<int, 2>> qry;

const int X=19;
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

void solve() {
	qry.clear();
	cin >> n >> t >> a >> b ;
	for (int i=1; i<=n; i++) {cin >> v[i]; if (v[i]==t) p=i;}

	array<int, 2> lm1={0, 0}, uab1={0, 0};
	for (int i=1; i<p; i++) lm1[v[i]>t]++;
	uab1[0]=!!lm1[1]; uab1[1]=!!lm1[0];

	array<int, 2> lm2={0, 0}, uab2={0, 0};
	for (int i=p+1; i<=n; i++) lm2[v[i]>t]++;
	uab2[0]=!!lm2[1]; uab2[1]=!!lm2[0];

	if (a<uab1[0]+uab2[0] || b<uab1[1]+uab2[1]){cout << "no\n"; return;}
	cout << "yes\n";

	for (int i=1; i<p-2; i++) {
		if (a-1>=uab1[0]+uab2[0]) qry.push_back({i, 0}), v[i+1]=min(v[i], v[i+1]), a--;
		else qry.push_back({i, 1}), v[i+1]=max(v[i], v[i+1]), b--;
	}

	if (p==2) {
		if (v[1]<v[2]) qry.push_back({1, 1}), b--;
		else qry.push_back({1, 0}), a--;
	}
	else if (p>=3) {
		if (v[p-2]<v[p] && v[p-1]<v[p]) {
			if (a-1>=uab2[0]) qry.push_back({p-2, 0}), a--;
			else qry.push_back({p-2, 1}), b--;
			qry.push_back({p-1, 1}); b--;
		}
		else if (v[p-2]<v[p] && v[p-1]>v[p]) {
			qry.push_back({p-2, 0}); a--;
			qry.push_back({p-1, 1}); b--;
		}
		else if (v[p-2]>v[p] && v[p-1]<v[p]) {
			qry.push_back({p-2, 1}); b--;
			qry.push_back({p-1, 0}); a--;
		}
		else {
			if (a-2>=uab2[0]) qry.push_back({p-2, 0}), a--;
			else qry.push_back({p-2, 1}), b--;
			qry.push_back({p-1, 0}); a--;
		}
	}

	for (int i=n; i>p+2; i--) {
		if (a-1>=uab2[0]) qry.push_back({i-1, 0}), v[i-1]=min(v[i], v[i-1]), a--;
		else qry.push_back({i-1, 1}), v[i-1]=max(v[i], v[i-1]), b--;
	}

	if (p==n-1) {
		if (v[n-1]<v[n]) qry.push_back({n-1, 0}), a--;
		else qry.push_back({n-1, 1}), b--;
	}
	else if (p<=n-2) {
		if (v[p+2]<v[p] && v[p+1]<v[p]) {
			if (a>=1) qry.push_back({p+1, 0}), a--;
			else qry.push_back({p+1, 1}); b--;
			qry.push_back({p, 1}); b--;
		}
		else if (v[p+2]<v[p] && v[p+1]>v[p]) {
			qry.push_back({p+1, 0}); a--;
			qry.push_back({p, 1}); b--;
		}
		else if (v[p+2]>v[p] && v[p+1]<v[p]) {
			qry.push_back({p+1, 1}); b--;
			qry.push_back({p, 0}); a--;
		}
		else {
			if (a>=2) qry.push_back({p+1, 0}), a--;
			else qry.push_back({p+1, 1}), b--;
			qry.push_back({p, 0}); a--;
		}
	}

	for (int i=1; i<=n; i++) update(i, 1-sum(i, i));
	for (array<int, 2>& i : qry) {
		update(i[0], -1); i[0]=sum(1, i[0])+1;
	}

	for (array<int, 2> i : qry) cout << (i[1]==1?"M":"m"); cout << "\n";
	for (array<int, 2> i : qry) cout << i[0] << " ";
	cout << "\n";
}

signed main() {
	fastio;

	int T; cin >> T;
 	while (T--) solve();

	return 0;
}
