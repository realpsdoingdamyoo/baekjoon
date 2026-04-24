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

ll n, q;
pii wei[100003];
vi ufa[100003];

void diff(ll a, ll b){
    if(wei[a][0]==wei[b][0]) cout << wei[b][1]-wei[a][1] << "\n";
    else cout << "UNKNOWN\n";
}

void unionfind(ll a, ll b, ll c){
    c+=wei[a][1]-wei[b][1];
    a=wei[a][0]; b=wei[b][0];
    if(a==b) return;

    if(ufa[wei[a][0]].size()<ufa[wei[b][0]].size()){
        swap(a, b); c=-c;
    }

    for(ll i : ufa[b]){
        ufa[a].pb(i);
        wei[i]={a, wei[i][1]+c};
    }
    ufa[b].clear();


    return;
}

int main() {
    fastio;

    while(1){
        cin >> n >> q;
        if(!n && !q) break;
        forf(i, 0, n){
            wei[i]={i, 0};
            ufa[i].clear();
            ufa[i].pb(i);
        }

        while(q--){
            char s; cin >> s;
            if(s=='!'){
                ll a, b, c; cin >> a >> b >> c;
                unionfind(a-1, b-1, c);
            }
            else{
                ll a, b; cin >> a >> b;
                diff(a-1, b-1);
            }
        }
    }



	return 0;
}
