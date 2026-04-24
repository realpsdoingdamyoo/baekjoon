#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

typedef uint64_t u;

const int us=64, sz=800;

struct B{
    vector<u> v;
    B(int s=sz){v.resize(s/us+1, 0);}
};

B one;

bool IDX(B& b, int idx){
    int j=idx%us;
    return b.v[idx/us]>>j&1;
}

void SET(B& b, int idx, int val){
    int j=idx%us;
    if(val) b.v[idx/us]|=1ll<<j;
    else b.v[idx/us]&=~1ll<<j;
}

void OR(B& a, B b){
    for(int i=0; i<a.v.size(); i++) a.v[i]|=b.v[i];
}

B SHIFT(B a, int s){
    B ret=a;
    int q=s/us, r=s%us;
    for (int i=0; i<a.v.size(); i++) {
        if (i+q<ret.v.size()) ret.v[i + q]|=a.v[i]<<r;
        if (r && i+q+1<ret.v.size()) ret.v[i+q+1]|=a.v[i]>>(us-r);
    }
    return ret;
}

int bag(vector<int> V) {
    int cnt[51]={}, S=0;
    for (int i : V) cnt[i]++, S+=i;
    if (S%2) return false;
    B bt(S+1); SET(bt, 0, 1);

    for (int i=1; i<=50; i++) {
        int k=1;
        while (k<=cnt[i]) OR(bt, SHIFT(bt, k*i)), cnt[i]-=k, k<<=1;
        if (cnt[i]) OR(bt, SHIFT(bt, cnt[i]*i));
    }
    return IDX(bt, S/2);
}

int N, M;
vector<array<int, 2>> lnk[101010];

int vis[101010], pr[101010], pd[101010], dep[101010];

bool dfs(int p) {
    vis[p]=1;
    for (array<int, 2> i : lnk[p]) if (i[0]!=pr[p]) {
        if (vis[i[0]]) {
            if (dep[i[0]]<dep[p]) {
                int x=p; vector<int> U={i[1]};
                while (x!=i[0]) U.push_back(pd[x]), x=pr[x];
                if (!bag(U)) return false;
            }
        }
        else {
            pr[i[0]]=p; pd[i[0]]=i[1]; dep[i[0]]=dep[p]+1;
            if (!dfs(i[0])) return false;
        }
    }
    return true;
}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c}); lnk[b].push_back({a, c});
    }
    for (int i=1; i<=N; i++) if (!vis[i])
        if (!dfs(i)) {cout << "NO"; return 0;}
    cout << "YES";

    return 0;
}
