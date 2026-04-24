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

vector<vi> v, vv;
ll n;

void vvset(ll bit){
    forf(i, 0, n){
        forf(j, 0, n){
            vv[i][j]=v[i][j]^(!!(bit&(1<<i)));
        }
    }
}

ll vvmin(){
    ll ret=0;
    forf(i, 0, n){
        ll s=0;
        forf(j, 0, n){
            s+=vv[j][i];
        }
        ret+=min(s, n-s);
    }
    return ret;
}

int main() {
    cin >> n;
    v.resize(n); vv.resize(n);
    forf(i, 0, n){
        v[i].resize(n); vv[i].resize(n);
        string s; cin >> s;
        forf(j, 0, n) v[i][j]=(s[j]=='T');
    }
    ll mn=n*n;
    forf(i, 0, (1<<n)){
        vvset(i);
        mn=min(mn, vvmin());
        //cout << i << " " << vvmin() << endl;
    }
    cout << mn;

    return 0;
}
