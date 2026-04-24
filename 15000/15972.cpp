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

    ll n, m, h; cin >> n >> m >> h;
    V<vpii> lnk(n*m+1);
    forf(i, -1, n){
        forf(j, 0, m){
            ll a; cin >> a;
            if(a!=-1){
                if(i==-1){
                    lnk[n*m].pb({(i+1)*m+j, a});
                    lnk[(i+1)*m+j].pb({n*m, a});
                }
                else if(i==n-1){
                    lnk[n*m].pb({i*m+j, a});
                    lnk[i*m+j].pb({n*m, a});
                }
                else{
                    lnk[i*m+j].pb({(i+1)*m+j, a});
                    lnk[(i+1)*m+j].pb({i*m+j, a});
                }
            }
        }
    }
    forf(i, 0, n){
        forf(j, -1, m){
            ll a; cin >> a;
            if(a!=-1){
                if(j==-1){
                    lnk[n*m].pb({i*m+j+1, a});
                    lnk[i*m+j+1].pb({n*m, a});
                }
                else if(j==m-1){
                    lnk[n*m].pb({i*m+j, a});
                    lnk[i*m+j].pb({n*m, a});
                }
                else{
                    lnk[i*m+j+1].pb({i*m+j, a});
                    lnk[i*m+j].pb({i*m+j+1, a});
                }
            }
        }
    }

    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({0, n*m});
    vi w(n*m+1), vsd(n*m+1); forf(i, 0, n*m) w[i]=h;

    while(pq.size()){
        ll p=pq.top()[1], d=pq.top()[0]; pq.pop();
        if(vsd[p]) continue;
        vsd[p]=1;
        for(pii i : lnk[p]){
            if(w[i[0]]<=max(d, i[1])) continue;
            w[i[0]]=max(d, i[1]);
            pq.push({max(d, i[1]), i[0]});
        }
    }


    /*forf(i, 0, n){
        forf(j, 0, m) cout << w[i*m+j] << " ";
        cout << "\n";
    }*/

    ll s=0;
    forf(i, 0, n*m) s+=w[i];
    cout << s;


    return 0;
}
