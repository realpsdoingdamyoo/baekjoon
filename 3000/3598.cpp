#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e11;

int h, a, b, c;

int dist[101010], vis[101010];

signed main() {
	fastio;

	cin >> h >> a >> b >> c; h--;
	if (a<b) swap(a, b); if (a<c) swap(a, c);

	for (int i=1; i<a; i++) dist[i]=inf;

	list<int> q; q.push_back(0);

	while (q.size()) {
		int p=q.front(); q.pop_front();
		if (vis[p]++) continue;

		dist[(p+b)%a]=min(dist[(p+b)%a], dist[p]+(p+b>=a));
		if (p+b<a) q.push_front((p+b)%a); else q.push_back((p+b)%a);
		dist[(p+c)%a]=min(dist[(p+c)%a], dist[p]+(p+c>=a));
		if (p+c<a) q.push_front((p+c)%a); else q.push_back((p+c)%a);
	}

	int ans=0;
	for (int i=0; i<a; i++) if (dist[i]!=inf)  {
		int s=dist[i]*a+i;
		int e=h-h%a+i; e-=a*(e>h);
		if (s>e) continue;
		ans+=(e-s)/a+1;
	}
	cout << ans << "\n";

	return 0;
}
