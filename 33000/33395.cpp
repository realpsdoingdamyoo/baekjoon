#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

long long n, ret;
int v[1010101], ans[1010101];
priority_queue<int, vector<int>, greater<int>> pq;

signed main(){
    fastio;

    cin >> n;
    for(int i=1; i<=n; i++) cin >> v[i];
    sort(v+1, v+n+1);

    for(int i=1; i<=n; i++){
        v[i]-=i; pq.push(v[i]); pq.push(v[i]);
        pq.pop(); ans[i]=min(0, pq.top());
    }
    ans[n+1]=-9e9;
    for(int i=n; i>=1; i--){
        ans[i]=max(ans[i], ans[i+1]);
        ret+=abs(ans[i]-v[i]);
    }
    cout << ret;
}
