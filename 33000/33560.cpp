#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef __float128 lf;
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
#define cf cout.flush()

int main(){
    fastio;

    ll n; cin >> n;
    vi v(n); vcin;

    ll t=0, tp=4, c=0, p=1;
    ll get[4]={};

    forf(i, 0, n){
        if(t>240){
            if(c<35){}
            else if(c<65) get[0]++;
            else if(c<95) get[1]++;
            else if(c<125) get[2]++;
            else get[3]++;
            t=0; tp=4; c=0; p=1;
        }

        if(v[i]==1){
            if(c<35){}
            else if(c<65) get[0]++;
            else if(c<95) get[1]++;
            else if(c<125) get[2]++;
            else get[3]++;
            t=0; tp=4; c=0; p=1;
        }
        else if(v[i]==2){
            if(p>1) p/=2;
            else tp+=2;
        }
        else if(v[i]==4){
            t+=56;
        }
        else if(v[i]==5){
            tp-=(tp>1);
        }
        else if(v[i]==6){
            p*=1+(p<32);
        }

        if(v[i]!=1){
            c+=p;
            t+=tp;
        }
    }

    forf(i, 0, 4) cout << get[i] <<"\n";

    return 0;
}
