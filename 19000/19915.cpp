#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, A, AN, B, BN, C, CN;
vector<int> lnk[101010];
vector<int> sp[101010];

int VIS[101010], S[101010];
vector<int> R(101010);

void TB(int p) {
    VIS[p]=1;
    for (int i : lnk[p]) if (!VIS[i]) {
        sp[p].push_back(i);
        sp[i].push_back(p);
        TB(i);
    }
}

int CEN;

void SZ(int p, int x) {
    S[p]=1;
    for (int i : sp[p]) if (i!=x) {
        SZ(i, p); S[p]+=S[i];
    }
}

int GC(int p, int x) {for (int i : sp[p]) if (i!=x && S[i]>N/2) return GC(i, p); return p;}

void PA(int p, int x, int c, int& l) {
    if (l>0) R[p]=c, l--;
    for (int i : sp[p]) if (i!=x) {
        PA(i, p, c, l);
    }
}

int T[101010];
vector<int> H[101010];
void TC(int p, int x, int c) {
    T[p]=c; H[c].push_back(p);
    for (int i : sp[p]) if (i!=x) TC(i, p, c);
}

vector<int> TL[101010];

void DFS(int p, vector<int>& vec) {
    VIS[p]=1; vec.push_back(p);
    for (int i : TL[p]) if (!VIS[i]) DFS(i, vec);
}

int O[101010];

void PA2(int p, int c, int &l) {
    if (l>0) R[p]=c, l--; VIS[p]=1;
    for (int i : lnk[p]) if (!VIS[i] && O[T[i]]) PA2(i, c, l);
}

void PA3(int p, int c, int& l) {
    if (l>0) R[p]=c, l--; VIS[p]=1;
    for (int i : lnk[p]) if (!VIS[i] && R[i]==0) PA3(i, c, l);
}

vector<int> find_split(int n, int a, int b, int c, vector<int> u, vector<int> v) {
    N=n; A=a; AN=1; B=b; BN=2; C=c; CN=3;
    if (A>B) swap(A, B), swap(AN, BN);
    if (B>C) swap(B, C), swap(BN, CN);
    if (A>B) swap(A, B), swap(AN, BN);

    for (int i=0; i<u.size(); i++) {
        lnk[u[i]+1].push_back(v[i]+1);
        lnk[v[i]+1].push_back(u[i]+1);
    }

    TB(1);

    SZ(1, 0);
    CEN=GC(1, 0);
    SZ(CEN, 0);

    for (int i : sp[CEN]) {
        if (S[i]>=A) {
            PA(i, CEN, AN, A);
            PA(CEN, i, BN, B);
            for (int j=1; j<=N; j++) if (!R[j]) R[j]=CN;
            return vector<int>(R.begin()+1, R.begin()+N+1);
        }
    }

    for (int i : sp[CEN]) TC(i, CEN, i);

    for (int i=1; i<=N; i++) for (int j : lnk[i]) if (i!=CEN && j!=CEN) TL[T[i]].push_back(T[j]);

    fill(VIS+1, VIS+N+1, 0);

    for (int i : sp[CEN]) if (!VIS[i]) {
        vector<int> vec;
        DFS(i, vec);

        int ps=0;
        for (int j : vec) ps+=H[j].size();
        if (ps<A) continue;

        for (int j : vec) O[j]=1;

        fill(VIS+1, VIS+N+1, 0); PA2(i, AN, A);
        fill(VIS+1, VIS+N+1, 0); PA3(CEN, BN, B);

        for (int j=1; j<=N; j++) if (!R[j]) R[j]=CN;
        return vector<int>(R.begin()+1, R.begin()+N+1);
    }

    return vector<int>(N, 0);
}
