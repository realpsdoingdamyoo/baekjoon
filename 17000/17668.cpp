#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

struct sq {
	vector<int> x;
	int isq, idx;
};
bool cmpv(vector<int>& a, vector<int>& b) {
	for (int i=0; i<a.size(); i++) {
		if (a[i]==b[i]) continue;
		return a[i]<b[i];
	} return false;
}
bool cmp(sq& a, sq& b) {
	if (a.x==b.x) return a.isq>b.isq;
	return cmpv(a.x, b.x);
}

int n, N, Q;
int ans[101010];

const int X=18;
int seg[1<<X+1];
void update(int p, int x) {
	p+=1<<X;
	while (p) seg[p]+=x, p>>=1;
}
int sum(int s, int e) {
	int r=0; s+=1<<X; e+=1<<X;
	while (s<=e) {
		if (s&1) r+=seg[s]; ++s>>=1;
		if (~e&1) r+=seg[e]; --e>>=1;
	} return r;
}

void dnc(vector<sq> v) {
	for (int t : {0, 1}) {
		vector<int> cr;
		for (sq i : v) cr.push_back(i.x[t]);
		sort(cr.begin(), cr.end());
		cr.erase(unique(cr.begin(), cr.end()), cr.end());

		for (sq& i : v) i.x[t]=lower_bound(cr.begin(), cr.end(), i.x[t])-cr.begin();
	}

	sort(v.begin(), v.end(), cmp);

	int s=v.size();

	reverse(v.begin(), v.end());
	for (sq i : v) {
	    if (!i.isq) update(i.x[1], 1);
		else ans[i.idx]+=sum(i.x[1], s);
	}
	for (sq i : v) if (!i.isq) update(i.x[1], -1);

}

void cdq(vector<sq> v){
	if (v.size()<=1) return;

	int m=v.size()/2;

	vector<sq> L, R;
	for (int i=0; i<m; i++) L.push_back(v[i]);
	for (int i=m; i<v.size(); i++) R.push_back(v[i]);
	cdq(L); cdq(R);

	vector<sq> C;
	for (int i=0; i<m; i++) if (v[i].isq){
		sq nsq=v[i]; nsq.x.erase(nsq.x.begin());
		C.push_back(nsq);
	}
	for (int i=m; i<v.size(); i++) if (!v[i].isq) {
		sq nsq=v[i]; nsq.x.erase(nsq.x.begin());
		C.push_back(nsq);
	}
	dnc(C);
}

signed main() {
	fastio;

	cin >> N >> Q; n=N+Q;
	vector<sq> v;
	for (int i=1; i<=N; i++) {
		int a, b; cin >> a >> b;
		sq ts;
		ts.x={a, b, a+b}; ts.isq=0; ts.idx=0;
		v.push_back(ts);
	}
	for (int i=N+1; i<=N+Q; i++) {
		int a, b, c; cin >> a >> b >> c;
		sq tq;
		tq.x={a, b, c}; tq.isq=1; tq.idx=i-N;
		v.push_back(tq);
	}

	sort(v.begin(), v.end(), cmp);
	cdq(v);
	for (int i=1; i<=Q; i++) cout << ans[i] << "\n";

	return 0;
}
