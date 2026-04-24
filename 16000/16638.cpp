#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
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
const vpii dir4={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vpii dir8={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf cout.flush()

ll cal(vpii v){
    ll n=v.size();
    vpii u;

    forf(i, 0, n){
        if(v[i][0]=='*') u.back()[1]*=v[i][1];
        else u.pb(v[i]);
    }

    ll ret=0;
    for(pii i : u){
        if(i[0]=='+') ret+=i[1];
        else ret-=i[1];
    }
    return ret;
}

int main(){
    fastio;

    ll n; cin >> n; n=n+1>>1;
    string s; cin >> s;
    s="+"+s;

    vpii v;

    forf(i, 0, n){
        v.pb({s[i*2], s[i*2+1]-'0'});
    }

    ll ans=-inf-123456;

    forf(bit, 0, 1<<n){
        if(bit&(bit<<1|1)) continue;

        vpii u;
        forf(i, 0, n){
            if(bit&(1<<i)){
                if(v[i][0]=='+') u.back()[1]+=v[i][1];
                if(v[i][0]=='-') u.back()[1]-=v[i][1];
                if(v[i][0]=='*') u.back()[1]*=v[i][1];
            }
            else u.pb(v[i]);
        }

        ans=max(ans, cal(u));
    }

    cout << ans;


    return 0;
}
