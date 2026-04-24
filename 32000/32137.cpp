#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
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

vi ord[2];
vi vsd[2];
pii ck[3];
V<set<ll>> l[2];

void dfs(ll pnt, ll id){
    if(l[id][pnt].size()>2) return;
    ck[id][l[id][pnt].size()]++;
    ord[id].pb(pnt);
    vsd[id][pnt]=1;
    for(ll i : l[id][pnt]){
        if(!vsd[id][i]) dfs(i, id);
    }
}

ll ssb(vi v){
    V<bool> u(v.size());
    ll c=v.size();
    forf(i, 0, v.size()){
        if(u[i]) continue;
        ll j=v[i]; u[i]=true;
        while(j!=i){
            u[j]=true;
            j=v[j];
        }
        c--;
    }
    return c;
}

int main(){
    fastio;

    ll n; cin >> n;
    vpii v(n*n);
    l[0].resize(n); l[1].resize(n);
    vsd[0].resize(n); vsd[1].resize(n);

    forf(i, 0, n){
        forf(j, 0, n){
            ll a; cin >> a; a--;
            v[a]={i, j};
        }
    }

    forf(i, 0, n*n-1){
        pii a=v[i], b=v[i+1];

        if(a[0]==b[0]){
            l[0][a[1]].insert(b[1]);
            l[0][b[1]].insert(a[1]);
        }
        else if(a[1]==b[1]){
            l[1][a[0]].insert(b[0]);
            l[1][b[0]].insert(a[0]);
        }
        else{
            cout << "-1";
            return 0;
        }
    }

    ll ckck[2]={};
    forf(i, 0, n){
        if(l[0][i].size()==1 && ckck[0]==0)
            dfs(i, 0), ckck[0]=1;
        if(l[1][i].size()==1 && ckck[1]==0)
            dfs(i, 1), ckck[1]=1;
    }

    if(!(ck[0][1]==2 && ck[0][2]==n-2 && ck[1][1]==2 && ck[1][2]==n-2)){
        cout << "-1";
        return 0;
    }

    ll ret=0;
    forf(i, 0, 2){
        ll x=ssb(ord[i]);
        reverse(all(ord[i]));
        ll y=ssb(ord[i]);
        ret+=min(x, y);
    }
    cout << ret;

    return 0;
}
