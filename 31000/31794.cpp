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
    ll n;
    string s; cin >> s; n=s.length()*2+1;
    vi mnc=manacher(s);
    vi mana(n+5);
    forf(i, 0, mnc.size()){
        if(i%2==0){
            mana[i/2-mnc[i]/2]++;
            mana[i/2]--;
            mana[i/2+1]--;
            mana[i/2+mnc[i]/2+1]++;
        }
        else{
            mana[i/2-mnc[i]/2]++;
            mana[i/2+1]-=2;
            mana[(i+mnc[i])/2+1]++;
        }
    }

    forf(i, 1, n) mana[i]+=mana[i-1];
    forf(i, 1, n) mana[i]+=mana[i-1];

    ll q; cin >> q;
    while(q--){
        ll k; cin >> k;
        cout << mana[k-1] << "\n";
    }


    return 0;
}
