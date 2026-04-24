#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef string S;
#define V vector
#define PQ priority_queue
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define all(v) v.begin(), v.end()
const ll mod=1e9+7, MOD=998244353;
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


int main(){
    //fastio;

    ll n, k; cin >> n >> k;
    vi L, R, v(n), vsd(n+1);
    PQ<pii> pq;
    forf(i, 0, n){
        cin >> v[i];
        pq.push({v[i], i});
        L.pb((i+n-1)%n);
        R.pb((i+1)%n);
    }

    ll ans=0;

    while(k--){
        while(vsd[pq.top()[1]]) pq.pop();
        pii t=pq.top();
        ans+=t[0]; pq.pop();

        v[t[1]]=v[L[t[1]]]+v[R[t[1]]]-v[t[1]];
        pq.push({v[t[1]], t[1]});
        vsd[L[t[1]]]=vsd[R[t[1]]]=1;

        L[t[1]]=L[L[t[1]]];
        R[t[1]]=R[R[t[1]]];
        R[L[t[1]]]=t[1];
        L[R[t[1]]]=t[1];
    }

    cout << ans;

    return 0;
}
