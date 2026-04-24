#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, k, ans;
vector<array<int, 3>> v;

void dnc(array<int, 2> s, array<int, 2> e){
    if(s==e) return;
    int X=s[1]-e[1], Y=e[0]-s[0];

    array<int, 2> r={0, 0};
	for(array<int, 3>& i : v) i[0]=X*i[1]+Y*i[2];
	sort(v.begin(), v.end());
	for(int i=0; i<k; i++) r[0]+=v[i][1], r[1]+=v[i][2];

	ans=min(ans, r[0]*r[1]);
	if(s==r || r==e) return;
	dnc(s, r); dnc(r, e);
}

signed main(){
	fastio;

	cin >> n >> k;
	v.resize(n);
	for(array<int, 3>& i : v) cin >> i[1] >> i[2];

	array<int, 2> ft={0, 0};
	for(array<int, 3>& i : v) i[0]=i[1];
	sort(v.begin(), v.end());
	for(int i=0; i<k; i++) ft[0]+=v[i][1], ft[1]+=v[i][2];

	array<int, 2> st={0, 0};
	for(array<int, 3>& i : v) i[0]=i[2];
	sort(v.begin(), v.end());
	for(int i=0; i<k; i++) st[0]+=v[i][1], st[1]+=v[i][2];

	ans=min(ft[0]*ft[1], st[0]*st[1]);
	dnc(ft, st);

	cout << ans;

    return 0;
}
