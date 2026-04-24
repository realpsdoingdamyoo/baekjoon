#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef priority_queue<ll> pqi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, c) sort(v.begin(), v.end(), c)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

bool cmp(pii a, pii b){return a[1]<b[1];}

int main(){
    fastio;
    
    ll n; cin >> n;
    vpii v(n);
    forf(i, 0, 2) forf(j, 0, n) cin >> v[j][i];
    sortc(v, cmp);
    pqi pq; ll s=v[0][0];
    forf(i, 0, n/2-1){
        pq.push(v[i*2+1][0]);
        pq.push(v[i*2+2][0]);
        s+=pq.top(); pq.pop();
    }
    cout << s << "\n";
    return 0;
}
