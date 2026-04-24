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

ll n, q;
set<ll> st[202020];
ll grp[202020];
vi tree[202020];
ll njh[202020], mny[202020];


void dfs(ll pnt, ll mn){
    mny[pnt]+=njh[pnt]+mn;
    for(ll i : tree[pnt])
        dfs(i, mn+njh[pnt]);
}

int main(){
    fastio;

    cin >> n >> q;
    forf(i, 1, n+1){
        grp[i]=i;
        st[i].insert(i);
    }
    while(q--){
        ll a, b, c; cin >> a >> b >> c;
        if(a==1){
            b=grp[b]; c=grp[c];
            if(st[b].size()<st[c].size()) swap(b, c);
            tree[b].pb(c);
            njh[c]-=njh[b];

            for(ll i : st[c]){
                st[b].insert(i);
                grp[i]=b;
            }
            st[c].clear();
        }
        else{
            mny[b]+=c; c/=st[grp[b]].size();
            njh[grp[b]]-=c;
        }
    }



    dfs(grp[1], 0);

    V<tii> ans;

    forf(i, 1, n){
        if(mny[i]==0) continue;
        ans.pb({i, i+1, -mny[i]});
        mny[i+1]+=mny[i];
    }

    cout << ans.size() << "\n";
    for(tii t : ans){
        if(t[2]<0){
            swap(t[0], t[1]); t[2]*=-1;
        }
        cout << t[0] << " " << t[1] << " " << t[2] << "\n";
    }

    return 0;
}
