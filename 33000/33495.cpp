#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef string S;
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
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


int main(){
    fastio;

    string s; cin >> s;
    ll ksac[3]={};
    forf(i, 0, s.length()){
        if(s[i]=='K') ksac[0]++;
        if(s[i]=='S') ksac[1]++;
        if(s[i]=='A') ksac[2]++;
    }
    ll kl=min(ksac[0], min(ksac[1], ksac[2]));
    if(ksac[0]>kl && ksac[1]>kl) kl=kl*3+2;
    else if(ksac[0]>kl) kl=kl*3+1;
    else kl=kl*3;

    string ksa="KSA";

    ll c=kl;
    forb(i, s.length(), 0){
        if(c==0) break;
        if(ksa[(c-1)%3]==s[i]) c--;
    }


    cout << s.length()-(kl-c);


    return 0;
}
