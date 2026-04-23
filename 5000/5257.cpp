#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m;
array<int, 5> ans;
vector<array<int, 5>> v;

int g[202];

int Find(int x){return g[x]<0?x:Find(g[x]);}
int Union(int a, int b){
    a=Find(a); b=Find(b);
    if(a==b) return 0;
    if(-g[a]<-g[b]) swap(a, b);
    g[a]+=g[b]; g[b]=a;
    return 1;
}

array<int, 2> mst(int X, int Y, int p=0){
	for(array<int, 5>& i : v) i[0]=X*i[3]+Y*i[4];
	sort(v.begin(), v.end());

	for(int i=0; i<n; i++) g[i]=-1;

	array<int, 2> ret={0, 0};
	for(array<int, 5> i : v){
        int x=Union(i[1], i[2]);
        ret[0]+=x*i[3];
        ret[1]+=x*i[4];
        if(p && x) cout << i[1] << " " << i[2] << "\n";
	}
	return ret;
}

void dnc(array<int, 2> s, array<int, 2> e){
    if(s==e) return;
    int X=s[1]-e[1], Y=e[0]-s[0];

    array<int, 2> r=mst(X, Y);

	ans=min(ans, {r[0]*r[1], r[0], r[1], X, Y});
	if(s==r || r==e) return;
	dnc(s, r); dnc(r, e);
}

signed main(){
	fastio;

	cin >> n >> m;
	v.resize(m);
	for(array<int, 5>& i : v) cin >> i[1] >> i[2] >> i[3] >> i[4];

	array<int, 2> ft=mst(1, 0), st=mst(0, 1);

	ans=min(array<int, 5>{ft[0]*ft[1], ft[0], ft[1], 1, 0}, {st[0]*st[1], st[0], st[1], 0, 1});
	dnc(ft, st);

	cout << ans[1] << " " << ans[2] << "\n\n";
	mst(ans[3], ans[4], 1);

    return 0;
}
