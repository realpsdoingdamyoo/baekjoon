#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main(){
    ll n, s=0; cin >> n;
    priority_queue<ll> pq;
    for(int i=0; i<n; i++){
        int k; cin >> k; pq.push(-k);
    }
    for(int i=0; i<n-1; i++){
        ll p=pq.top(); pq.pop();
        ll q=pq.top(); pq.pop();
        s+=p+q;
        pq.push(p+q);
    }
    cout << -s;
    return 0;
}
