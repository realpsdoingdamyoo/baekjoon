#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m, q;
vector<int> lnk[303030];
vector<array<int, 3>> upd[303030];
vector<array<int, 4>> qry[303030];
long long ans[303030];

int v[313030], r[313030], RB[303030];

int U1L[751], U1LL;
vector<array<int, 3>> U2L[751];

int V[303030];

void lzu(int p);

const int X=400, Y=750;
struct bucket {
    int L, R, U, T, RS;
    int vmx=0, vmxc=0;
    int cnt=0, sum=0, mx=0, mxc=0;

    inline void update() {
        int p=RB[L], TU=U2L[p].size();

        if (TU) {
            for (int i=L; i<=R; i++) {
                if (v[i]+mx==n+1) r[i]+=mxc, RS+=mxc;
                v[i]+=sum;
            }
            vmx=0; vmxc=0; sum=0; mx=-1; mxc=0;
            for (array<int, 3> i : U2L[p]) V[i[0]]+=i[2], V[i[1]+1]-=i[2];
            for (int i=L; i<=R; i++) V[i]+=V[i-1], v[i]+=V[i]+sum;
            fill(V+L, V+R+2, 0);
            U2L[p].clear();

            for (int i=L; i<=R; i++) {
                if (v[i]==vmx) vmxc++;
                if (v[i]>vmx) vmx=v[i], vmxc=1;
            }
        }
        sum+=U1L[p]+U1LL; U1L[p]=0;
        if (sum==mx) mxc++;
        if (sum>mx) mx=sum, mxc=1;
    }

    int drag(int s, int e) {
        int ret=0;
        for (int i=max(L, s); i<=min(R, e); i++) {
            ret+=r[i];
            if (v[i]+mx==n+1) ret+=mxc;
        }
        return ret;
    }
} bck[Y];

void update(int s, int e, int x) {
    if (RB[s]==RB[e]) {
        U2L[RB[s]].push_back({s, e, x});
        return;
    }

    if (s%X!=1) {
        U2L[RB[s]].push_back({s, bck[RB[s]].R, x});
        s=bck[RB[s]].R+1;
    }

    if (e%X!=0) {
        U2L[RB[e]].push_back({bck[RB[e]].L, e, x});
        e=bck[RB[e]].L-1;
    }

    int S=RB[s], E=RB[e];
    if (E-S>Y/2) {
        for (int i=0; i<=S-1; i++) U1L[i]-=x;
        for (int i=E+1; i<=Y-1; i++) U1L[i]-=x;
        U1LL+=x;
    }
    else {
        for (int i=S; i<=E; i++) U1L[i]+=x;
    }
}

long long query(int s, int e) {
    long long ret=0;
    for (int i=RB[s]; i<=RB[e]; i++) {
        bucket& B=bck[i];
        if (s<=B.L && B.R<=e) ret+=(B.mx+B.vmx==n+1)*B.vmxc*B.mxc+B.RS;
        else ret+=B.drag(s, e);
    }
    return ret;
}

signed main(){
    fastio;

    cin >> n >> m >> q;
    for (int i=1; i<=n; i++) lnk[i].push_back(0);
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(i);
        lnk[b].push_back(i);
    }
    for (int i=1; i<=n; i++) lnk[i].push_back(m+1);

    for (int i=1; i<=q; i++) {
        int a, b; cin >> a >> b;
        qry[a-1].push_back({i, a, b, -1});
        qry[b].push_back({i, a, b, 1});
    }

    for (int i=1; i<=n; i++) {
        for (int j=0; j+1<lnk[i].size(); j++) {
            int ls=lnk[i][j]+1, le=lnk[i][j+1]-1;
            int rs=lnk[i][j]+1, re=lnk[i][j+1]-1;
            if (rs<=re) upd[ls].push_back({rs, re, 1});
            if (rs<=re) upd[le+1].push_back({rs, re, -1});
        }
        for (int j=0; j+3<lnk[i].size(); j++) {
            int ls=lnk[i][j]+1, le=lnk[i][j+1];
            int rs=lnk[i][j+2], re=lnk[i][j+3]-1;
            upd[ls].push_back({rs, re, 1});
            upd[le+1].push_back({rs, re, -1});
        }
    }


    for (int i=1; i<=m; i++) {
        upd[i].push_back({i+1, m, 1});
        upd[i+1].push_back({i+1, m, -1});
    }

    for (int i=0; i<Y; i++) {
        bck[i].L=i*X+1;
        bck[i].R=i*X+X;
        bck[i].vmxc=X;
        for (int j=bck[i].L; j<=bck[i].R; j++) RB[j]=i;
    }

    for (int i=1; i<=m; i++) {
        for (array<int, 3> j : upd[i]) update(j[0], j[1], j[2]);
        for (int j=0; j<Y; j++) bck[j].update(); U1LL=0;

        for (array<int, 4> j : qry[i]) ans[j[0]]+=query(j[1], j[2])*j[3];
    }

    for (int i=1; i<=q; i++) cout << ans[i] << "\n";

    return 0;
}
