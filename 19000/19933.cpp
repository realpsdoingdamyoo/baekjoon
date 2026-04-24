#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int N, K, H[202020], RH[202020];

const int MX=202020;
int seg[MX*4], lzy[MX*4];

void update(int p, int l, int r, int s, int e, int x) {
    if (r<s || e<l) return;
    if (s<=l && r<=e) lzy[p]+=x;
    else {
        int m=l+r>>1;
        update(p<<1, l, m, s, e, x);
        update(p<<1|1, m+1, r, s, e, x);
        seg[p]=min(seg[p<<1]+lzy[p<<1], seg[p<<1|1]+lzy[p<<1|1]);
    }
}

int left(int p, int l, int r, int s, int e) {
    if (seg[p]+lzy[p]>0) return inf;
    if (r<s || e<l) return inf;
    if (l==r) return l;
    lzy[p<<1]+=lzy[p]; lzy[p<<1|1]+=lzy[p]; seg[p]+=lzy[p]; lzy[p]=0;
    int m=l+r>>1;
    int a=left(p<<1, l, m, s, e); if (a<N) return a;
    return left(p<<1|1, m+1, r, s, e);
}

int minq(int p, int l, int r, int s, int e) {
    if (r<s || e<l) return inf;
    if (s<=l && r<=e) return seg[p]+lzy[p];
    int m=l+r>>1;
    return min(minq(p<<1, l, m, s, e), minq(p<<1|1, m+1, r, s, e))+lzy[p];
}

void _update(int s, int e, int x) {
    s=(s+N*10)%N; e=(e+N*10)%N;
    if (s<=e) update(1, 0, N-1, s, e, x);
    else update(1, 0, N-1, s, N-1, x), update(1, 0, N-1, 0, e, x);
}

int _left(int s, int e) {
    s=(s+N*10)%N; e=(e+N*10)%N;
    if (s<=e) return left(1, 0, N-1, s, e);
    int a=left(1, 0, N-1, s, N-1), b=left(1, 0, N-1, 0, e);
    return a>N?b:a;
}

int _minq(int s, int e) {
    s=(s+N*10)%N; e=(e+N*10)%N;
    if (s<=e) return minq(1, 0, N-1, s, e);
    return min(minq(1, 0, N-1, s, N-1), minq(1, 0, N-1, 0, e));
}

const int X=19;
int mm[1<<X+1];
void update2(int p, int x) {
    p+=1<<X; mm[p]=x; p>>=1;
    while (p) mm[p]=max(mm[p<<1], mm[p<<1|1]), p>>=1;
}
int max2(int s, int e) {
    s+=1<<X; e+=1<<X; int r=-inf;
    while (s<=e) {
        if (s&1) r=max(mm[s], r); ++s>>=1;
        if (~e&1) r=max(mm[e], r); --e>>=1;
    } return r;
}

int _max2(int s, int e) {
    s=(s+N*10)%N; e=(e+N*10)%N;
    if (s<=e) return max2(s, e);
    return max(max2(0, e), max2(s, N-1));
}

int qp[202020];

int canp(int p) {
    return _minq(p, p)==0 && _minq(p-K+1, p-1)>0;
}

array<long long, 2> gL[202020][20], gR[202020][20];

void init(int k, vector<int> R) {
    N=R.size(); queue<int> q; K=k;
    for (int i=0; i<N; i++) update(1, 0, N-1, i, i, R[i]);
    for (int i=0; i<N; i++) {
        if (canp(i)) q.push(i), qp[i]=1;
    }

    for (int t=N; t>=1; t--) {
        int p=q.front(); q.pop(); H[p]=t; RH[t]=p;
        _update(p-K+1, p-1, -1);
        _update(p, p, N+10);
        int a=_left(p-K+1, p-1), b=_left(p+1, p+K-1);
        if (a<N && !qp[a] && canp(a)) qp[a]=1, q.push(a);
        if (b<N && !qp[b] && canp(b)) qp[b]=1, q.push(b);
    }

    for (int t=1; t<=N; t++) {
        int p=RH[t];
        int l=_max2(p-K+1, p-1), r=_max2(p+1, p+K-1);
        if (l!=0) gL[t][0]={l, (p-RH[l]+N)%N}; else gL[t][0]={t, 0};
        if (r!=0) gR[t][0]={r, (RH[r]-p+N)%N}; else gR[t][0]={t, 0};
        update2(p, t);
    }

    for (int j=1; j<20; j++) for (int i=1; i<=N; i++) {
        gL[i][j][0]=gL[gL[i][j-1][0]][j-1][0];
        gL[i][j][1]=gL[gL[i][j-1][0]][j-1][1]+gL[i][j-1][1];
        gR[i][j][0]=gR[gR[i][j-1][0]][j-1][0];
        gR[i][j][1]=gR[gR[i][j-1][0]][j-1][1]+gR[i][j-1][1];
    }

}

long long goL(int x, int y) {
    long long d=0;
    for (int i=19; i>=0; i--) if (gL[x][i][0]>=y) d+=gL[x][i][1], x=gL[x][i][0];
    return d;
}
long long goR(int x, int y) {
    long long d=0;
    for (int i=19; i>=0; i--) if (gR[x][i][0]>=y) d+=gR[x][i][1], x=gR[x][i][0];
    return d;
}

int hasp(int x, int y) {
    return goL(H[x], H[y])>=(x-y+N)%N || goR(H[x], H[y])>=(y-x+N)%N;
}

int compare_plants(int x, int y) {
    return hasp(x, y)-hasp(y, x);
}
