#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e10, bnd=1e10;

int n, m, q;
vector<int> lnk[101010];
int tr[101010];
vector<array<int, 2>> qr[101010];
int ans[101010];

int in[101010], out[101010], cnt=0;
int dep[101010], sp[101010][18];

void dfs(int p, int pre){
    in[p]=++cnt;
    for(int i : lnk[p]) if(i!=pre){
        dep[i]=dep[p]+1; sp[i][0]=p;
        for(int j=1; j<18; j++) sp[i][j]=sp[sp[i][j-1]][j-1];
        dfs(i, p);
    }
    out[p]=cnt;
}

int lca(int a, int b){
    if(dep[a]<dep[b]) swap(a, b);
    for(int i=0; i<18; i++) if(dep[a]-dep[b]&(1<<i)) a=sp[a][i];
    if(a==b) return a;
    for(int i=17; i>=0; i--)
        if(sp[a][i]!=sp[b][i])
            a=sp[a][i], b=sp[b][i];
    return sp[a][0];
}

const int X=17;
array<int, 2> seg[1<<X+1];

void sup(int p, int x, int sq){
    array<int, 2> up={sq, x};
    p+=1<<X;
    while(p) seg[p]=up, p>>=1;
}

int tup(int s, int e){
    array<int, 2> ret={0, 0};
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) ret=max(ret, seg[s]);
        if(~e&1) ret=max(ret, seg[e]);
        ++s>>=1; --e>>=1;
    }
    return ret[1];
}

int lsg[1<<X+1];

void lsgtree(){
    for(int i=1; i<=m; i++) lsg[i+(1<<X)]=tr[i];
    for(int i=(1<<X)-1; i>=1; i--){
        lsg[i]=lca(lsg[i<<1], lsg[i<<1|1]);
    }
}

int Lca(int s, int e){
    int r=0; s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) r=r?lca(r, lsg[s]):lsg[s];
        if(~e&1) r=r?lca(r, lsg[e]):lsg[e];
        ++s>>=1; --e>>=1;
    }
    return r;
}

int close(int p, int x){
    if(tup(in[p], out[p])!=x) return p;
    for(int i=17; i>=0; i--){
        if(sp[p][i]==0) continue;
        if(tup(in[sp[p][i]], out[sp[p][i]])==x) p=sp[p][i];
    }
    return sp[p][0];
}


int Seg[1<<X+1];

void Update(int p, int x){
    p+=1<<X; Seg[p]=x; p>>=1;
    while(p) Seg[p]=Seg[p<<1]+Seg[p<<1|1], p>>=1;
}

int Sum(int s, int e){
    s+=1<<X; e+=1<<X;
    int ret=0;
    while(s<=e){
        if(s&1) ret+=Seg[s];
        if(~e&1) ret+=Seg[e];
        ++s>>=1; --e>>=1;
    }
    return ret;
}

int rct=0;
void update(int p, int pin){
    int np=p;
    while(1){
        np=close(np, 0);
        if(np==0) break;

        int t=tup(in[np], out[np]);
        Update(t, dep[tr[t]]-dep[np]);
        np=close(np, t);
    }
    sup(in[p], pin, rct++);
}

signed main(){
    fastio;

    cin >> n >> m >> q;
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }
    dfs(1, 0);

    for(int i=1; i<=m; i++) cin >> tr[i];

    for(int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        qr[b].push_back({a, i});
    }

    lsgtree();

    for(int i=1; i<=m; i++){
        update(tr[i], i);
        for(array<int, 2> j : qr[i]){
            ans[j[1]]=Sum(j[0], i-1)+dep[tr[i]]-dep[Lca(j[0], i)]+1;
        }
        Update(i, dep[tr[i]]-dep[lca(tr[i], tr[i+1])]);
    }

    for(int i=0; i<q; i++) cout << ans[i] << "\n";

    return 0;
}
