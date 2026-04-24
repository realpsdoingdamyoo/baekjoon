#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(ll not_used_name=0; not_used_name<n; not_used_name++)
#define all(v) v.begin(), v.end()
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double PI=acos(-1), EU=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

string S="_", P;


vi getpi(string p){
    int m=p.length(), j=0;
    vi pi(m);
    for(int i=1; i<m; i++){
        while(j>0 && p[i]!=p[j]) j=pi[j-1];
        if(p[i]==p[j]) pi[i]=++j;
    }
    return pi;
}

ll kmp(string s, string p){
    ll ret=0;
    ll n=s.length(), m=p.length(), j=0;
    vi pi=getpi(p);
    vi ans;
    for(int i=0; i<n; i++){
        while(j>0 && s[i]!=p[j]) j=pi[j-1];
        if(s[i]==p[j]){
            if(j==m-1) return m;
            else j++;
        }
        ret=max(ret, j);
    }
    return ret;
}

int main() {
    fastio;
    cin >> P; ll n=P.length();
    forf(i, 0, n) S+=P.substr(i, 1)+"_";

    string p1, p2;
    forf(i, 0, n){
        p1+=(i%2?"_":P.substr(i, 1));
        p2+=(i%2?P.substr(i, 1):"_");
    }
    //cout << S << "\n" << p1 << "\n" << p2 << "\n";

    cout << max(kmp(S, p1), kmp(S, p2)) << "\n";

    return 0;
}
