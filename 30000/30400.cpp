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

vi manacher(string p){
    string s="_";
    forf(i, 0, p.length()) s+=p.substr(i, 1)+"_";
    //cout << s << "\n";
    ll n=s.length();
    vi mnc(n);

    ll r=0, c=0;
    forf(i, 0, n){
        if(i<=r) mnc[i]=min(r-i, mnc[c*2-i]);
        while(i+mnc[i]<n-1 && mnc[i]<i && s[i+mnc[i]+1]==s[i-mnc[i]-1]) mnc[i]++;
        if(i+mnc[i]>r){c=i; r=i+mnc[i];}
    }
    return mnc;
}

int main() {
    fastio;

    ll n, m; cin >> n >> m;
    string s; cin >> s;
    vi mnc=manacher(s);
    vpii palin;

    forf(i, 0, mnc.size()){
        if(mnc[i]>=m){
            palin.pb({(i-min(mnc[i], m))/2, (i+min(mnc[i], m)-1)/2});
        }
    }
    sortv(palin);
    ll mxd=-1, c=0;
    for(auto i : palin){
        if(mxd<i[0]){
            c++; mxd=i[1];
        }
    }

    cout << c;

    return 0;
}
