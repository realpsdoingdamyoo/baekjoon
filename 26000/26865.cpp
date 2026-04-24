#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

signed main(){
    fastio;

    int N, K, R=0; cin >> N >> K;
    priority_queue<int, vector<int>, greater<int>> pq;
    int X[110];
    for (int i=1; i<=N; i++) cin >> X[i];
    for (int i=1; i<=K; i++) pq.push(0);
    sort(X+1, X+N+1);
    for (int i=1; i<=N; i++) {
        int x=pq.top(); pq.pop();
        R+=x; pq.push(x+X[i]);
    }
    while (pq.size()) R+=pq.top(), pq.pop();
    cout << R << "\n";


    return 0;
}
