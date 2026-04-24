#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;
#define si signed

int N, Q;
vector<array<int, 2>> lnk[101010];

int sp[101010][20], dep[101010], dis[101010];
int in[101010], out[101010], pv, F[101010];
void dfs(int p, int x) {
    in[p]=++pv;
    for (array<int, 2> i : lnk[p]) if (i[0]!=x) {
        sp[i[0]][0]=p; for (int j=1; j<20; j++) sp[i[0]][j]=sp[sp[i[0]][j-1]][j-1];
        dep[i[0]]=dep[p]+1; dis[i[0]]=dis[p]+i[1]; dfs(i[0], p);
        F[p]=max(F[p], F[i[0]]+i[1]);
    }
    out[p]=pv;
}

int F1[101010], F2[101010], Fv[101010];
void dfs2(int p, int x, int pd) {
    for (array<int, 2> i : lnk[p]) if (i[0]!=x) {
        int nd=F[i[0]]+i[1];
        if (nd>F1[p]) F2[p]=F1[p], F1[p]=nd, Fv[p]=i[0];
        else if (nd>F2[p]) F2[p]=nd;
    }
    for (array<int, 2> i : lnk[p]) if (i[0]!=x) {
        int d=pd;
        if (F[p]!=F[i[0]]+i[1]) d=max(d, F[p]);
        else d=max(d, F2[p]);
        dfs2(i[0], p, d+i[1]);
    }
    if (pd>F1[p]) F2[p]=F1[p], F1[p]=pd, Fv[p]=(p==1?p:x);
    else if (pd>F2[p]) F2[p]=pd;
}

int lca(int a, int b) {
    if (dep[a]<dep[b]) swap(a, b);
    for (int i=19; i>=0; i--) if ((dep[a]-dep[b])&1<<i) a=sp[a][i];
    if (a==b) return a;
    for (int i=19; i>=0; i--) if (sp[a][i]!=sp[b][i]) a=sp[a][i], b=sp[b][i];
    return sp[a][0];
}

int dn(int p, int x){return in[p]<=in[x] && in[x]<=out[p];}
int far(int x, int p) {
    if (dn(p, x)) {if (dn(p, Fv[p]) && dn(Fv[p], x)) return F2[p]; return F1[p];}
    if (dn(Fv[p], p)) return F2[p]; return F1[p];
}

int solve1(int s, int t, int v1, int v2) {
    int w=lca(s, t);
    if (v2*(dis[s]-dis[w])<v1*(dis[t]-dis[w])) {
        int c=t;
        for (int i=19; i>=0; i--) {
            int u=sp[c][i];
            if (dep[u]>=dep[w] && v2*(dis[s]+dis[u]-2*dis[w])>=v1*(dis[t]-dis[u])) c=u;
        }
        c=sp[c][0];
        return dis[t]-dis[c]+far(t, c);
    }
    else {
        int c=s;
        for (int i=19; i>=0; i--) {
            int u=sp[c][i];
            if (dep[u]>=dep[w] && v2*(dis[s]-dis[u])<v1*(dis[t]+dis[u]-2*dis[w])) c=u;
        }
        return dis[t]+dis[c]-2*dis[w]+far(t, c);
    }
}

int solve2(int s, int t, int v1, int v2) {
    int w=lca(s, t);
    int diswt=dis[t]-dis[w], dist=dis[s]-dis[w]+diswt, ret=0;
    if ((v2-v1)*far(t, s)>=v1*dist) return v2*dist;

    if ((v2-v1)*far(t, w)<=(v1+v2)*diswt-v2*dist) {
        int x=t;
        for (int i=19; i>=0; i--) {
            int u=sp[x][i];
            if (dep[u]>=dep[w] && (v2*(dis[s]+dis[u]-2*dis[w])>=v1*(dis[t]-dis[u]) || (v2-v1)*far(t, u)>(v1+v2)*(dis[t]-dis[u])-v2*dist)) x=u;
        }
        if (v2*(dis[s]+dis[x]-2*dis[w])<v1*(dis[t]-dis[x])) ret=2*v2*(dis[t]-dis[x])-v2*dist;
        x=sp[x][0];
        ret=max(ret, (v2-v1)*(dis[t]-dis[x]+far(t, x)));
        return ret;
    }
    else {
        int x=s;
        for (int i=19; i>=0; i--) {
            int u=sp[x][i];
            if (dep[u]<dep[w]) continue;
            if (v2*(dis[s]-dis[u])<v1*(dis[t]+dis[u]-2*dis[w]) && (v2-v1)*far(t, u)<=(v1+v2)*(dis[t]+dis[u]-2*dis[w])-v2*dist) x=u;
        }
        ret=(v2-v1)*(dis[t]+dis[x]-2*dis[w]+far(t, x));
        x=sp[x][0];
        if (v2*(dis[s]-dis[x])<v1*(dis[t]+dis[x]-2*dis[w])) ret=max(ret, 2*v2*(dis[t]+dis[x]-2*dis[w])-v2*dist);
        return ret;
    }
}

vector<array<int, 2>> police_thief(vector<si> A, vector<si> B, vector<si> D, vector<si> P, vector<si> V1, vector<si> T, vector<si> V2) {
    N=A.size()+1; Q=P.size();

    for (int i=0; i<N-1; i++) {
        A[i]++; B[i]++;
        lnk[A[i]].push_back({B[i], D[i]});
        lnk[B[i]].push_back({A[i], D[i]});
    }
    dep[1]=1; dfs(1, 0); dfs2(1, 0, 0);
    vector<array<int, 2>> ans(Q);
    for (int i=0; i<Q; i++) {
        if (V2[i]>=V1[i]) ans[i][0]=solve1(T[i]+1, P[i]+1, V2[i], V1[i]);
        else ans[i][0]=solve2(T[i]+1, P[i]+1, V2[i], V1[i]);
        ans[i][1]=V1[i];
        if (V1[i]>V2[i]) ans[i][1]*=V1[i]-V2[i];
        int g=__gcd(ans[i][0], ans[i][1]);
        ans[i][0]/=g; ans[i][1]/=g;
    }
    return ans;
}
