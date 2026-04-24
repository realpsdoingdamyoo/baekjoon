#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

ll c[300005], mo[300005], n, m, s[300005], sz[300005];
priority_queue<ll> q[300005];

int main(){
    cin >> n >> m;
    for(int i=2; i<=n+m; i++) {
        cin >> mo[i] >> c[i];
    }
    for(int i=n+1; i<=n+m; i++){q[i].push(0); q[i].push(0);}
    for(int i=n+m; i>=1; i--){
        while(sz[i]--) q[i].pop();
        ll l=q[i].top(); q[i].pop();
        ll r=q[i].top(); q[i].pop();
        q[i].push(l+c[i]); q[i].push(r+c[i]);
        s[mo[i]]+=s[i]+c[i];
        sz[mo[i]]+=!!q[mo[i]].size();
        if(q[mo[i]].size()<q[i].size()) swap(q[i], q[mo[i]]);
        while(q[i].size()){q[mo[i]].push(q[i].top()); q[i].pop();}
    }
    q[0].pop();
    while(q[0].size()){s[0]-=q[0].top(); q[0].pop();}
    cout << s[0];
}
