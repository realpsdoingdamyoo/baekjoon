#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

priority_queue<int> pq;

int main() {
	ll n, t, p, x, c=0, mx=0, cc=0;
	cin >> n >> t >> p;

	int sum = 0;
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		sum+=x; c++;
		pq.push(x);

		while (sum+i*p>t && c) {
			if (t<p*i){sum=c=0; break;}
			c--; sum-=pq.top(); pq.pop();
		}

		mx = max(mx, c);
	}

	printf("%d", mx);
}
