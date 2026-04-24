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
const vpii dir4={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vpii dir8={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double PI=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

typedef array<ll, 4> qii;
ll n, m, X=400;
ll g[50505];
ll out[101010];
vpii vec;
V<tii> lnklist, lnklistp;

ll Find(ll x){return g[x]>0?Find(g[x]):x;}

void Union(ll a, ll b){
    a=Find(a); b=Find(b);
    if(a==b) vec.pb({0, 0}), vec.pb({0, 0});
    else{
        if(-g[a]>-g[b]) swap(a, b);
        vec.pb({a, g[a]}); vec.pb({b, g[b]});
        g[b]+=g[a]; g[a]=b;
    }
}

void rollback(){
    g[vec.back()[0]]=vec.back()[1]; vec.pop_back();
    g[vec.back()[0]]=vec.back()[1]; vec.pop_back();
}

// 1 다리번호 비용 쿼리번호
// 2 무게 출발섬 쿼리번호

bool cmplnk(tii& a, tii& b){
    return a[2]<b[2];
}

bool cmpprq(qii& a, qii& b){
    return a[1]>b[1];
}

void solve(V<qii>& queries){

    V<tii> lnk; // 안건드리는 간선 / u v cost
    V<qii> prq; // 2 _ _ _
    vpii ans;

    // 안건드리는 간선 찾기 + 출력쿼리 빼놓기
    for(qii i : queries){
        if(i[0]==1) out[i[1]]=1;
        else prq.pb(i);
    }

    // 안건드리는 간선 lnk에 싹 넣어놓기
    for(ll i=0; i<m; i++) if(!out[i]) lnk.pb(lnklist[i]);
    sortc(lnk, cmplnk);

    // prq 이쁘게 정렬하기
    sortc(prq, cmpprq);

    for(qii Q : prq){ //  Q : 2 무게 출발섬 쿼리번호
        while(lnk.size() && lnk.back()[2]>=Q[1]){
            Union(lnk.back()[0], lnk.back()[1]);
            lnk.pop_back();
        }

        for(ll i=0; i<Q[3]; i++){
            qii& x=queries[i];
            if(x[0]==2) continue;
            lnklist[x[1]][2]=x[2];
        }

        ll cnt=0;
        for(ll i=0; i<queries.size(); i++){
            if(queries[i][0]==2) continue;
            ll cn=queries[i][1];
            if(lnklist[cn][2]>=Q[1]){
                Union(lnklist[cn][0], lnklist[cn][1]);
                cnt++;
            }
        }

        ans.pb({Q[3], -g[Find(Q[2])]});
        while(cnt--) rollback();

        for(ll i=0; i<Q[3]; i++){
            qii& x=queries[i];
            if(x[0]==2) continue;
            lnklist[x[1]][2]=lnklistp[x[1]][2];
        }
    }

    sortv(ans);
    for(pii i : ans) cout << i[1] << "\n";

    for(qii i : queries){
        if(i[0]==2) continue;
        lnklistp[i[1]][2]=lnklist[i[1]][2]=i[2];
        out[i[1]]=0;
    }
    while(vec.size()) rollback();

}



int main(){
    fastio;
    cin >> n >> m;
    for(ll i=1; i<=n; i++) g[i]=-1;
    forf(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        lnklist.pb({a, b, c});
        lnklistp.pb({a, b, c});
    }

    ll q; cin >> q;
    V<V<qii>> querieses;
    forf(i, 0, q){
        ll a, b, c; cin >> a >> b >> c;
        if(i%X==0) querieses.pb({});
        if(a==1) b--; else swap(b, c);
        querieses.back().pb({a, b, c, i%X});
    }

    for(V<qii>& i : querieses) solve(i);

    return 0;
}
