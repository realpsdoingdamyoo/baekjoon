#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

const int M=40, T=1LL<<40;
int DP[M+1][M+1][M+1];

int dv(int a, int b) {
    return (a+T*50)/b-T*50/b;
}

int mid(int l, int r) {
    int s=dv(l+T-1, T), e=dv(r, T);
    if (s<=e) {
        if (s<=0 && 0<=e) return 0;
        if (0<s) return s*T;
        if (e<0) return e*T;
    }

    for (int i=39; i>=0; i--) {
        int X=1LL<<i;
        s=dv(l+X-1, X); e=dv(r, X);
        if (s<=e) return s*X;
    }
    return 0;
}

const int X=15;
int seg[2<<X];
void update(int p, int x) {
    p+=1<<X; seg[p]=x; p>>=1;
    while (p) seg[p]=seg[p<<1]+seg[p<<1|1], p>>=1;
}
int sum(int s, int e) {
    s+=1<<X; e+=1<<X; int r=0;
    while (s<=e) {
        if (s&1) r+=seg[s]; ++s>>=1;
        if (~e&1) r+=seg[e]; --e>>=1;
    } return r;
}

signed main(){
    fastio;

    for (int i=0; i<=M; i++) for (int j=0; j<=M; j++) for (int k=0; k<=M; k++) {
        if (i==0 && j==0 && k==1) DP[i][j][k]=-T;
        else if (k==0) DP[i][j][k]=(i+j)*T;
        else {
            int L=-inf, R=(i+j)*T;
            if (i) L=max(L, (i-1)*T);
            if (j) L=max(L, DP[i][j-1][k]);
            if (k>1) L=max(L, DP[i][j][k-1]);
            DP[i][j][k]=mid(L+1, R-1);
        }
    }

    int N; cin >> N;
    for (int t=1; t<=N; t++) {
        int R, C, SS[44][44]={}; char V[44][44];
        cin >> R >> C;
        for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) cin >> V[i][j];

        reverse(V+1, V+R+1);

        int cnt[3]={}, tt=-1; array<int, 2> P[3];
        for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) cnt[V[i][j]-'A']++, P[V[i][j]-'A']={i, j};

        if (cnt[1]==1) {
            for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) if (V[i][j]!='C') V[i][j]='A'+'B'-V[i][j];
            swap(P[0], P[1]); tt=1;
        }

        int C1=0, C2=0, C3=0, val, k=inf;
        for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) if (V[i][j]=='B') {
            if (i<=P[0][0] && j<=P[0][1]) C1++;
            else if (i>=P[0][0] && j>=P[0][1]) C2++;
            else C3++, SS[i][j]++;
        }
        for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) SS[i][j]+=SS[i-1][j]+SS[i][j-1]-SS[i-1][j-1];
        for (int i=1; i<=R; i++) for (int j=1; j<=C; j++)
            if (V[i][j]=='B' && i>=P[0][0] && j>=P[0][1]) k=min(k, SS[i][j]);
        if (C2==0) val=DP[0][C3][C1+1];
        else val=DP[C2+C3-k][k][C1+1];
        update(t, tt*val);
    }

    int Q; cin >> Q;
    while (Q--) {
        int x, s, e; cin >> x >> s >> e;
        update(x, -sum(x, x));
        int v=sum(s, e);
        if (v>0) cout << "Ahgus\n";
        else cout << "Bagus\n";
    }

    return 0;
}
