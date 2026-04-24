#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef stack<ll> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n; cin >> n;
	vector<ll> smin(n+1), smax(n+1);
	ll x,ans=0;
	stack<array<ll, 2>> stmin, stmax;
	stmin.push({0,0}); stmax.push({1LL<<50,0});
	for(int i=1;i<=n;i++){
		cin >> x;
		while(stmin.top()[0]>x) stmin.pop();
		while(stmax.top()[0]<x) stmax.pop();
		smin[i]=smin[stmin.top()[1]]+(i-stmin.top()[1])*x;
		smax[i]=smax[stmax.top()[1]]+(i-stmax.top()[1])*x;
		ans+=smax[i]-smin[i];
		stmin.push({x,i}); stmax.push({x,i});
	}
	cout << ans;
}
