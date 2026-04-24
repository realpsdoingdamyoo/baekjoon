#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

int main() {
    fastio;

    ll n; cin >> n;
    vi v; ll s=0;
    repeat(n){
        ll k; cin >> k;
        if(v.size()==0) v.push_back(k);
        else if(v.size()==1){
            if(v[0]<k){
                s+=k;
                v.pop_back();
            }
            v.push_back(k);
        }
        else{
            while(v.size()>1 && v[v.size()-1]<=k){
                s+=min(v[v.size()-2], k);
                v.pop_back();
            }
            if(v.size()==1){
                if(v[0]<k){
                    s+=k;
                    v.pop_back();
                }
            }
            v.push_back(k);
        }
    }
    while(v.size()>1){
        s+=v[v.size()-2];
        v.pop_back();
    }
    cout << s << "\n";
    return 0;
}
