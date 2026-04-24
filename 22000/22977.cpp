#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define pb push_back
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll inf=2147483647, linf=9223372036854775807/10;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}



int main() {
    ll n, s=0; cin >> n;
    pii prev={0, 0};
    cin >> prev[0] >> prev[1];
    repeat(n-1){
        pii ar; cin >> ar[0] >> ar[1];
        if(ar[1]>prev[1]) s+=ar[1]-prev[1];
        if(ar[0]<prev[0]) s+=prev[0]-ar[0];
        prev=ar;
    }
    cout << s*2;
    return 0;
}
