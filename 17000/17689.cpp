#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n, k, s1, s2;
int dist[202020], L[202020], R[202020];
bool vsd[202020];
priority_queue<array<int, 2>> pq;

signed main() {
    fastio;

	cin >> n; k=n/2+n%2;
	dist[0]=dist[n+1]=-inf*2020200;
	R[0]=1; L[n+1]=n;

	for(int i=1; i<=n; i++){
		cin >> dist[i];
		pq.push({dist[i], i});
		L[i]=i-1;
		R[i]=i+1;
	}
	int s=0;

	while(k--){
		while(vsd[pq.top()[1]]) pq.pop();
		array<int, 2> t=pq.top();
		s+=t[0]; pq.pop();
		dist[t[1]]=dist[L[t[1]]]+dist[R[t[1]]]-dist[t[1]];
		pq.push({dist[t[1]], t[1]});
		vsd[L[t[1]]]=vsd[R[t[1]]]=true;
		L[t[1]]=L[L[t[1]]];
		R[t[1]]=R[R[t[1]]];
		R[L[t[1]]]=t[1];
		L[R[t[1]]]=t[1];
		cout << s << "\n";
	}
	return 0;
}
