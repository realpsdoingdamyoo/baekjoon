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

ll n;
V<vpii> cf; //capa, flow

ll FLOW(ll s, ll e){
    ll ret=0;

    while(1){
        vi from(n+1); from[s]=s;
        queue<ll> q; q.push(s);
        while(q.size() && !from[e]){
            ll p=q.front(); q.pop();
            forf(i, 1, n){
                if(cf[p][i][0]>cf[p][i][1] && !from[i]){
                    q.push(i);
                    from[i]=p;
                }
            }
        }
        if(!from[e]) break;

        ll flow=inf;
        for(ll i=e; i!=s; i=from[i]){
            flow=min(flow, cf[from[i]][i][0]-cf[from[i]][i][1]);
        }
        for(ll i=e; i!=s; i=from[i]){
            cf[from[i]][i][1]+=flow;
            cf[i][from[i]][1]-=flow;
        }

        ret+=flow;
    }
    return ret;
}


void changeflow(ll s, ll e){
    vi from(n); from[s]=s;
    queue<ll> q; q.push(s);
    while(q.size() && from[e]==0){
        ll p=q.front(); q.pop();
        forf(i, 1, n){
            if(p<s || (p==s && i<e)) continue;
            if(cf[p][i][0]-cf[p][i][1]>0 && from[i]==0){
                q.push(i);
                from[i]=p;
            }
        }
    }
    if(from[e]==0) return;

    cf[s][e][1]=cf[e][s][1]=0;
    for(ll i=e; i!=s; i=from[i]){
        cf[from[i]][i][1]++;
        cf[i][from[i]][1]--;
    }

}


int main(){
    fastio;

    ll h, w, s1=0, s2=0; cin >> h >> w;
    n=h+w+3;

    cf.resize(n+1);
    forf(i, 0, n+1) cf[i].resize(n+1);

    forf(i, 2, h+2){
        ll a; cin >> a;
        cf[1][i]={a, 0};
        cf[i][1]={0, 0};
        s1+=a;
    }
    forf(i, h+2, h+w+2){
        ll a; cin >> a;
        cf[i][n-1]={a, 0};
        cf[n-1][i]={0, 0};
        s2+=a;
    }
    forf(i, 2, h+2){
        forf(j, h+2, h+w+2){
            cf[i][j]={1, 0};
        }
    }

    ll fl=FLOW(1, n-1);

    if(s1!=fl || s2!=fl){
        cout << "-1";
        return 0;
    }

    forf(i, 2, h+2){
        forf(j, h+2, h+w+2){
            if(cf[i][j][1]) changeflow(i, j);
        }
    }

    forf(i, 2, h+2){
        forf(j, h+2, h+w+2){
            cout << cf[i][j][1];
        }
        cout << "\n";
    }


    return 0;
}
