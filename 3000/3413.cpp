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

    ll t; cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        V<tii> riv(n); V<pii> kni(m);
        forf(i, 0, n) forf(j, 0, 3) cin >> riv[i][j];
        forf(i, 0, m) forf(j, 0, 2) cin >> kni[i][j];
        ll div=n+1;
        forf(i, 0, n){
            forf(j, i+1, n){
                div+=!!(riv[i][0]*riv[j][1]-riv[i][1]*riv[j][0]);
            }
        }
        map<ll, ll> HASH;

        forf(i, 0, m){
            ll H=0;
            forf(j, 0, n){
                ll nh=(riv[j][0]*kni[i][0]+riv[j][1]*kni[i][1]+riv[j][2]>0);
                H=(H*2+nh)%(mod*MOD);
            }
            div-=!HASH[H];
            HASH[H]=1;
        }
        //cout << div << " ";
        if(div) cout << "VULNERABLE\n";
        else cout << "PROTECTED\n";

    }


    return 0;
}
