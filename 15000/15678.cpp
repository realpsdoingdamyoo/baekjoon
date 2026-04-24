#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[100005];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, l, k; cin >> n >> l;
    priority_queue<ll> pq1, pq2;
    vector<ll> v(n);
    
    for(int i=0; i<n; i++) cin >> v[i];
    ll dm=-1LL<<40;
    for(int i=0; i<n; i++){
         pq1.push(dp[i]);
         if(i>=l) pq2.push(dp[i-l]);
         while(!pq2.empty() && pq1.top()==pq2.top()){
             pq1.pop(); pq2.pop();
         }
         dp[i+1]=max(pq1.top(), 0LL)+v[i];
         dm=max(dp[i+1], dm);
         //cout << dp[i+1] << " ";
    }
    cout << dm << endl;
    return 0;
}
