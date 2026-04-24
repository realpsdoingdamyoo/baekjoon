#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int q, n=2;
array<int, 2> qry[1010101];

int P[1010101], L[1010101], R[1010101];
int RT[1010101];
vector<int> lnk[1010101];

const int X=20;
int seg0[1<<X+1], seg1[1<<X+1];

void update0(int s, int e, int x) {
    s+=1<<X; e+=1<<X;
    while (s<=e) {
        if (s&1) seg0[s]+=x; ++s>>=1;
        if (~e&1) seg0[e]+=x; --e>>=1;
    }
}
int val0(int p) {
    p+=1<<X; int r=0;
    while (p) r+=seg0[p], p>>=1;
    return r;
}
void update1(int p, int x) {
    p+=1<<X;
    while (p) seg1[p]+=x, p>>=1;
}
int sum1(int s, int e) {
    s+=1<<X; e+=1<<X; int r=0;
    while (s<=e) {
        if (s&1) r+=seg1[s]; ++s>>=1;
        if (~e&1) r+=seg1[e]; --e>>=1;
    } return r;
}

int vis[1010101], in[1010101], out[1010101];
int ord;
void dfs(int p) {
    in[p]=ord++; vis[p]=1;
    for (int i : lnk[p]) {
        if (i<0) L[-i]=ord;
        else dfs(i);
    }
    out[p]=ord-1;
    for (int i : lnk[p]) if (i<0) R[-i]=out[p];
}

signed main() {
    fastio;

    cin >> q;
    for (int i=1; i<=q; i++) {
        char a; int b; cin >> a >> b;
        if (a=='?') qry[i]={0, b};
        if (a=='W') qry[i]={1, b};
        if (a=='Z') qry[i]={2, b};
    }

    for (int i=1; i<=q+2; i++) P[i]=L[i]=R[i]=-1;
    P[2]=1; lnk[1].push_back(-2); RT[1]=1; RT[2]=2;

    for (int i=1; i<=q; i++) {
        if (qry[i][0]==1) {
            n++; RT[n]=n;
            lnk[qry[i][1]].push_back(-n);
            P[n]=qry[i][1];
        }
        if (qry[i][0]==2) {
            n++; RT[n]=RT[qry[i][1]];
            lnk[qry[i][1]].push_back(n);
            P[n]=P[qry[i][1]];
        }
    }

    for (int i=1; i<=n; i++) if (!vis[i]) dfs(i);

    update0(in[1], in[1], 1);
    update0(L[2], R[2], 1);

    int pv=2;
    for (int i=1; i<=q; i++) {
        int x=qry[i][1];

        if (qry[i][0]==0) {
            int ret=val0(in[x]);
            if (P[RT[x]]!=-1) ret++;
            ret+=sum1(L[RT[x]], R[RT[x]]);
            cout << ret << "\n";
        }
        else if (qry[i][0]==1) {
            update0(in[x], in[x], 1);
            ++pv; update0(L[pv], R[pv], 1);
        }
        else {
            ++pv; update0(L[RT[pv]], R[RT[pv]], 1);
            update1(in[pv], 1);
            if (P[RT[pv]]!=-1) update0(in[P[RT[pv]]], in[P[RT[pv]]], 1);
        }
    }

    return 0;
}
