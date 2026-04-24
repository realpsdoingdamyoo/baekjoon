#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

const int MX=202020;
const int X=20;
int N, pw[MX]={1};

struct tree {
    int g[MX];
    int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
    void Union(int a, int b){g[Find(a)]=Find(b);}

    vector<int> U[MX];
    vector<int> T[MX];

    void build() {
        for (int i=1; i<N; i++) {
            int a, b; cin >> a >> b;
            U[max(a, b)].push_back(min(a, b));
        }
        for (int i=1; i<=N; i++) g[i]=i;
        for (int i=1; i<=N; i++) {
            for (int j : U[i]) {
                T[i].push_back(Find(j));
                Union(j, i);
            }
        }
    }

    int seg[1<<X+1];
    void update(int s, int e, int x) {
        s+=1<<X; e+=1<<X;
        while (s<=e) {
            if (s&1) seg[s]+=x; ++s>>=1;
            if (~e&1) seg[e]+=x; --e>>=1;
        }
    }
    int val(int p) {
        p+=1<<X; int r=0;
        while (p) r+=seg[p], p>>=1;
        return r;
    }

    void Update(int p, int x) {
        p+=1<<X;
        while (p) seg[p]+=x, p>>=1;
    }
    int sum(int s, int e) {
        s+=1<<X; e+=1<<X; int r=0;
        while (s<=e) {
            if (s&1) r+=seg[s]; ++s>>=1;
            if (~e&1) r+=seg[e]; --e>>=1;
        }
        return r;
    }

    int pv, in[MX], out[MX], sp[MX][20], dep[MX], ppr[MX];

    void ett(int p) {
        for (int i=1; i<20; i++) sp[p][i]=sp[sp[p][i-1]][i-1];
        in[p]=++pv; for (int i : T[p]) sp[i][0]=p, dep[i]=dep[p]+1, ett(i); out[p]=pv;
    }

    int up(int p, int d) {
        for (int i=0; i<20; i++) if (d&(1<<i)) p=sp[p][i];
        return p;
    }

    bool isp(int p, int x) {
        if (dep[p]<dep[x]) return false;
        return up(p, dep[p]-dep[x])==x;
    }

} T1, T2;

int par[MX];
vector<int> rp[MX];

void dfs(int p) {
    int& x=par[p]=p;
    for (int i=19; i>=0; i--) if (T2.val(T2.in[T2.sp[x][i]])==T2.val(T2.in[p])) x=T2.sp[x][i];
    rp[x].push_back(p);
    T2.update(T2.in[p], T2.out[p], 1);
    for (int i : T1.T[p]) dfs(i);
    T2.update(T2.in[p], T2.out[p], -1);
}

int C[MX];

signed main(){
    fastio;

    for (int i=1; i<MX; i++) pw[i]=pw[i-1]*2%mod;

    cin >> N;
    T1.build(); T2.build();
    T1.ett(N); T2.ett(N); dfs(N);

    for (int i=1; i<=N; i++) {
        T1.ppr[i]=T1.up(i, T1.dep[i]-T1.dep[par[i]]-1);
        T2.ppr[i]=T2.up(i, T2.dep[i]-T2.dep[par[i]]-1);
    }

    int ans=0;
    for (int p=1; p<=N; p++) {
        C[p]++; int R=pw[C[p]]-1;
        map<int, int> mp1, mp2;
        for (int i : rp[p]) mp1[T1.ppr[i]]+=C[i];
        for (int i : rp[p]) mp1[T2.ppr[i]+N]+=C[i];
        for (int i : rp[p]) mp2[T1.ppr[i]*N+T2.ppr[i]]+=C[i];
        for (pair<int, int> i : mp1) R-=pw[i.second]-1;
        for (pair<int, int> i : mp2) R+=pw[i.second]-1;
        ans+=R%mod; C[par[p]]+=C[p];
    }
    cout << (ans%mod+mod)%mod;

    return 0;
}
