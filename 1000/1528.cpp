#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

vi gms, dp;

void gmss(){
    forf(i, 1, 7){
        forf(x, 0, 1<<i){
            ll ten=1, res=0;
            forf(j, 0, i){res+=ten*(4+3*!!(x&(1<<j))); ten*=10;}
            gms.push_back(res);
        }
    }
}

void ycj(ll n){
    if(n==0) return;
    forf(i, 0, gms.size()){
        if(gms[i]<=n){
            if(dp[n-gms[i]]==dp[n]-1){
                cout << gms[i] << " ";
                ycj(n-gms[i]);
                break;
            }
        }
    }
}

int main() {
    fastio;
    gmss();
    ll n; cin >> n; dp.resize(n+1);

    forf(i, 1, n+1){
        dp[i]=inf;
        forf(j, 0, gms.size()){
            if(i>=gms[j]) dp[i]=min(dp[i], dp[i-gms[j]]+1);
            else break;
        }
    }

    ycj(n);
    if(dp[n]>=inf) cout << "-1\n";
    return 0;
}
