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
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


vi getpi(vi p){
    int m=p.size(), j=0;
    vi pi(m);
    for(int i=1; i<m; i++){
        while(j>0 && p[i]!=p[j]) j=pi[j-1];
        if(p[i]==p[j]) pi[i]=++j;
    }
    return pi;
}

vi kmp(vi s, vi p){
    int n=s.size(), m=p.size(), j=0;
    vi pi=getpi(p);
    vi ans;
    for(int i=0; i<n; i++){
        while(j>0 && s[i]!=p[j]) j=pi[j-1];
        if(s[i]==p[j]){
            if(j==m-1) {ans.push_back(i-j); j=pi[j];}
            else j++;
        }
    }
    return ans;
}


int main() {
    fastio;

    ll r, n; cin >> r >> n;
    vi v; ll k=1, x; string bw;
    cin >> x >> bw;
    forf(i, 1, 2*n){
        ll x; string bwn;
        cin >> x >> bwn;
        if(bwn==bw) k++;
        else{
            v.pb(k);
            k=1;
            bw=bwn;
        }
    }
    v.pb(k);

    if(v.size()%2) {v[0]+=v[v.size()-1]; v.pop_back();}
    //forf(i, 0, v.size()) cout << v[i];
    vi pi=getpi(v);
    if(v.size()%(v.size()-pi[v.size()-1]) || (v.size()/(v.size()-pi[v.size()-1]))%2){
        cout << "-1\n";
    }
    else{
        ll t=v.size()-pi[v.size()-1];
        ll a=0;
        forf(i, 0, t) a+=v[i]*r;
        cout << a << "\n";
    }

    return 0;
}
