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


ll cost(string a, string b){
    array<ll, 26> alp;
    forf(i, 0, 26) alp[i]=0;
    forf(i, 0, a.length()) alp[a[i]-'a']++;
    forf(i, 0, b.length()) alp[b[i]-'a']--;
    bool k=false;
    forf(i, 0, 26) k=k||(alp[i]);
    if(k) return inf;
    else{
        ll s=0;
        forf(i, 0, a.length()){
            s+=!!(a[i]-b[i]);
        }
        return s;
    }
}

int main() {
    fastio;

    string s; cin >> s;
    ll n; cin >> n;
    vector<string> p(n);
    vi dp(s.length()+1);
    forf(i, 0, n) cin >> p[i];
    forf(i, 1, s.length()+1){
        dp[i]=inf;
        forf(j, 0, n){
            if(i>=p[j].length()){
                dp[i]=min(dp[i], dp[i-p[j].length()]+cost(p[j], s.substr(i-p[j].length(), p[j].length())));
            }
        }
    }

    if(dp[s.length()]>=inf) cout << "-1\n";
    else cout << dp[s.length()] << "\n";

    return 0;
}
