#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
#define V vector
#define PQ priority_queue
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
const ll mod=1e9+7, MOD=998244353, inf=2147483647;

ll n, m, r[2], R;
ll col[202020], inr[202020], dep[202020];
vi inrad, lnk[202020];
ll d0[202020], d[2][202020], D[202020];
ll ans[202020];
pii down[202020];

void dcal(ll p, ll pre, ll *d){
    if(p==pre) for(ll i=1; i<=n; i++) d[i]=inf*(i!=p);
    for(ll i : lnk[p]){
        if(i==pre) continue;
        d[i]=d[p]+1; dcal(i, p, d);
    }
}

void rad(){
    dcal(1, 1, d0);
    for(ll i=1; i<=n; i++) if(d0[r[0]]<d0[i]) r[0]=i;
    dcal(r[0], r[0], d[0]);
    for(ll i=1; i<=n; i++) if(d[0][r[1]]<d[0][i]) r[1]=i;
    dcal(r[1], r[1], d[1]);
    R=d[0][r[1]];
    vpii inrp;
    for(ll i=1; i<=n; i++) if(d[0][i]+d[1][i]==R) inrp.push_back({d[0][i], i});
    sortv(inrp);
    for(pii i : inrp) inrad.push_back(i[1]), inr[i[1]]=1;
}

void dfsd(ll p, ll pre){
    for(ll i : lnk[p]){
        if(i==pre) continue;
        dfsd(i, p);
        dep[p]=max(dep[p], dep[i]+1);
    }
}

map<ll, ll> mp;
set<ll> st;

struct seg{
    ll X=18;
    ll seg[1<<19];

    void update(ll s, ll e, ll x){
        s+=1<<X; e+=1<<X;
        while(s<=e){
            if(s&1) seg[s]+=x;
            if(~e&1) seg[e]+=x;
            ++s>>=1; --e>>=1;
        }
    }
    ll value(ll p){
        p+=1<<X; ll ret=0;
        while(p) ret+=seg[p], p>>=1;
        return !!ret;
    }
    void reset(){
        for(ll i=0; i<(1<<19); i++) seg[i]=0;
    }
} seg;


void Merge(pii& a, ll b){
    if(a[0]<b) swap(a[0], b);
    if(a[1]<b) swap(a[1], b);
}

void downdfs(ll p, ll pre){
    down[p]={0, 0};
    for(ll i : lnk[p]){
        if(i==pre) continue;
        downdfs(i, p);
        Merge(down[p], down[i][0]+1);
    }
}

vi stk;
void dfss(ll p, ll pre, ll t){
    if(!inr[p] && d[t][p]<d[t^1][p]) return;
    stk.push_back(p);

    if(d[t][p]<d[t^1][p] || (d[t][p]==d[t^1][p] && inr[p])){
        for(ll i : lnk[p]){
            if(i==pre) continue;
            ll dwn=(down[p][0]==down[i][0]+1?down[p][1]:down[p][0]);
            seg.update(d[t][p]-dwn, d[t][p]-1, 1);
            dfss(i, p, t);
            seg.update(d[t][p]-dwn, d[t][p]-1, -1);
        }
        return;
    }

    seg.update(d[t][p]-down[p][0], d[t][p]-1, 1);

    ll c1=0, cp1=0, c2=0, cp2=0;

    cp1=stk[d[t][p]-down[p][0]-1];
    if(seg.value(d[t][cp1])==0) mp[col[cp1]]++, c1++;

    if(d[t][p]-down[p][0]-2>=0){
        cp2=stk[d[t][p]-down[p][0]-2];
        if(seg.value(d[t][cp2])==0) mp[col[cp2]]++, c2++;
    }

    ans[p]=mp.size();

    /*cout << p << " / " ;
    cout << down[p][0] << " " << down[p][1] << " // ";
    for(pair<ll, ll> i : mp) cout << "[" << i.first << " " << i.second << "]";
    cout << "\n";
    for(ll i=0; i<n; i++) cout << seg.value(i) << " ";
    cout << "\n\n";*/

    seg.update(d[t][p]-down[p][0], d[t][p]-1, -1);

    for(ll i : lnk[p]){
        if(i==pre) continue;

        ll dwn=(down[p][0]==down[i][0]+1?down[p][1]:down[p][0]);
        seg.update(d[t][p]-dwn, d[t][p]-1, 1);

        dfss(i, p, t);

        seg.update(d[t][p]-dwn, d[t][p]-1, -1);
    }
    if(c1) if(!--mp[col[cp1]]) mp.erase(mp.find(col[cp1]));
    if(c2) if(!--mp[col[cp2]]) mp.erase(mp.find(col[cp2]));

    stk.pop_back();
}

int main(){
    fastio;

    cin >> n >> m;
    for(ll i=1; i<n; i++){
        ll a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }
    for(ll i=1; i<=n; i++) cin >> col[i];
    rad();


    st.clear(); mp.clear(); stk.clear(); seg.reset();
    downdfs(r[0], r[0]); dfss(r[0], r[0], 0);

    st.clear(); mp.clear(); stk.clear(); seg.reset();
    downdfs(r[1], r[1]); dfss(r[1], r[1], 1);

    for(ll i=1; i<=n; i++) cout << ans[i] << '\n';

    return 0;
}
