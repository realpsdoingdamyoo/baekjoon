#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int solve(int n, vector<int> arr) {
	priority_queue<int> pq;
	vector<int> ans(n);
	for(int i=0; i<n; i++){
		pq.push(arr[i]); pq.push(arr[i]); pq.pop();
		ans[i]=pq.top();
	}
	for(int i=n-2; i>=0; i--) if(ans[i]>ans[i+1]) ans[i]=ans[i+1];
	int s=0;
	for(int i=0; i<n; i++) s+=abs(arr[i]-ans[i]);
	return s;
}

signed main() {
	fastio;

	int n; cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int ans=solve(n, arr);
	reverse(arr.begin(), arr.end());
	ans=min(ans, solve(n, arr));
	cout << ans;

	return 0;
}
