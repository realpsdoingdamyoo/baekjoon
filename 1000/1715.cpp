#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


int main()
{
	fastio;
    ll s=0;
    int n; cin >> n;
    priority_queue<ll> pq;
    repeat(n){
        ll k; cin >> k; pq.push(-k);
    }
    repeat(n-1){
        ll a=-pq.top(); pq.pop();
        ll b=-pq.top(); pq.pop();
        pq.push(-a-b);
        s+=a+b;
    }
    cout << s;
    return 0;
}
