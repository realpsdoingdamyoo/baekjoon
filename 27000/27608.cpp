#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

const int B=320, MX=101010;
int N, M, Q;
int A1[MX], B1[MX];
int A2[MX], B2[MX];

int P1[MX], P1L[B], P1R[B];
int P2[MX], P2L[B], P2R[B];
array<int, 2> pr1[MX], pr2[MX];
inline int g(array<int, 2> a, array<int, 2> b) {return (a[0]+b[0])*(a[1]+b[1]);}

int sp[20][MX], nmx;
void dnc(int s, int e, int l, int r) {
    if (s>e) return;
    int m=s+e>>1, p=-1, v=-1;
    for (int i=l; i<=r; i++) {int c=g(pr1[m], pr2[i]); if (c>v) v=c, p=i;}
    sp[0][m]=v; nmx=max(nmx, v);
    dnc(s, m-1, p, r); dnc(m+1, e, l, p);
}

inline int qry(int s, int e) {int w=__lg(e-s+1); return max(sp[w][s], sp[w][e-(1<<w)+1]);}

vector<int> ans;
vector<int> build_teams(vector<signed> a1, vector<signed> b1, vector<signed> a2, vector<signed> b2, vector<signed> l1, vector<signed> r1, vector<signed> l2, vector<signed> r2) {
    N=a1.size(), M=a2.size(); Q=l1.size(); ans.resize(Q);
    for (int i=0; i<N; i++) A1[i+1]=a1[i], B1[i+1]=b1[i];
    for (int i=0; i<M; i++) A2[i+1]=a2[i], B2[i+1]=b2[i];
    for (int i=0; i<Q; i++) l1[i]++, r1[i]++, l2[i]++, r2[i]++;

    for (int i=1; i<=N; i++) P1[i]=(i-1)/B+1, P1R[P1[i]]=i;
    for (int i=N; i>=1; i--) P1L[P1[i]]=i;
    for (int i=1; i<=M; i++) P2[i]=(i-1)/B+1, P2R[P2[i]]=i;
    for (int i=M; i>=1; i--) P2L[P2[i]]=i;

    for (int i=0; i<Q; i++) {
        int M1=0, M2=0;
        int L1=l1[i], R1=r1[i], L2=l2[i], R2=r2[i];
        if (P1[L1]==P1[R1]) {
            for (int j=L1; j<=R1; j++) pr1[++M1]={A1[j], B1[j]};
        }
        else {
            for (int j=L1; j<=P1R[P1[L1]]; j++) pr1[++M1]={A1[j], B1[j]};
            for (int j=P1L[P1[R1]]; j<=R1; j++) pr1[++M1]={A1[j], B1[j]};
        }
        if (P2[L2]==P2[R2]) {
            for (int j=L2; j<=R2; j++) pr2[++M2]={A2[j], B2[j]};
        }
        else {
            for (int j=L2; j<=P2R[P2[L2]]; j++) pr2[++M2]={A2[j], B2[j]};
            for (int j=P2L[P2[R2]]; j<=R2; j++) pr2[++M2]={A2[j], B2[j]};
        }
        nmx=0; dnc(1, M1, 1, M2); ans[i]=nmx;
    }

    for (int i=1; i<=M; i++) pr1[i]={A2[i], B2[i]};
    for (int i=1; i<=P1[N]; i++) {
        int l=P1L[i], r=P1R[i];
        for (int j=l; j<=r; j++) pr2[j]={A1[j], B1[j]};
        dnc(1, M, l, r);
        for (int j=1; j<=19; j++) for (int p=1; p+(1<<j)-1<=M; p++)
            sp[j][p]=max(sp[j-1][p], sp[j-1][p+(1<<j-1)]);
        for (int j=0; j<Q; j++) if (l1[j]<=l && r<=r1[j]) ans[j]=max(ans[j], qry(l2[j], r2[j]));
    }
    for (int i=1; i<=N; i++) pr1[i]={A1[i], B1[i]};
    for (int i=1; i<=P2[M]; i++) {
        int l=P2L[i], r=P2R[i];
        for (int j=l; j<=r; j++) pr2[j]={A2[j], B2[j]};
        dnc(1, N, l, r);
        for (int j=1; j<=19; j++) for (int p=1; p+(1<<j)-1<=N; p++)
            sp[j][p]=max(sp[j-1][p], sp[j-1][p+(1<<j-1)]);
        for (int j=0; j<Q; j++) if (l2[j]<=l && r<=r2[j]) ans[j]=max(ans[j], qry(l1[j], r1[j]));
    }

    return ans;
}
