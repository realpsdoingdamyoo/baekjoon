#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N, M, K, r, c, v, d;

int C[500][500];
array<int, 2> S[110], E[110];
int I[110][110], X[110][110], A[110][110];

int inv(int x) {
    int r=1, p=mod-2;
    while (p) {if (p&1) r=r*x%mod; x=x*x%mod; p>>=1;}
    return r;
}
int det() {
    int R=1;
    for (int i=0; i<K; i++) {
        for (int j=i; j<K; j++) if (A[j][i]) {swap(A[i], A[j]); if (i!=j) R=mod-R; break;}
        if (A[i][i]==0) return 0; R=R*A[i][i]%mod;

        for (int j=i+1; j<K; j++) {
            int g=mod-A[j][i]*inv(A[i][i])%mod;
            for (int k=i; k<K; k++) A[j][k]=(A[j][k]+g*A[i][k])%mod;
        }
    }
    return R;
}

int P[110][110], V[110], R[110];
void gau() {
    for (int i=0; i<=K; i++) {P[i][0]=1; for (int j=1; j<=K; j++) P[i][j]=P[i][j-1]*i%mod;}
    for (int i=0; i<=K; i++) {
        for (int j=i; j<=K; j++) if (P[j][i]) {swap(P[i], P[j]); swap(V[i], V[j]); break;}
        for (int j=i+1; j<=K; j++) {
            int g=mod-P[j][i]*inv(P[i][i])%mod;
            for (int k=i; k<=K; k++) P[j][k]=(P[j][k]+g*P[i][k])%mod;
            V[j]=(V[j]+g*V[i])%mod;
        }
    }

    for (int i=K; i>=0; i--) {
        R[i]=V[i];
        for (int j=i+1; j<=K; j++) R[i]=(R[i]-P[i][j]*R[j]%mod+mod)%mod;
        R[i]=R[i]*inv(P[i][i])%mod;
    }
}

signed main() {
    fastio;

    for (int i=0; i<500; i++) for (int j=0; j<=i; j++)
        if (j==0) C[i][j]=1; else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;

    cin >> N >> M >> K >> r >> c >> v; K--; v--; r+=v-1; c+=v-1; d=r-c;

    for (int i=0; i<K; i++) for (int j=0; j<K; j++) if (j<=N+i && j>=i-M) {
        I[i][j]=C[N+M][N+i-j];
        for (int x=r, y=c; x>=j && y>=i; x--, y--) {
            int g=C[N-d][y-i]*C[M+d][x-j]%mod;
            if (x!=r) X[i][j]=(X[i][j]+g)%mod; I[i][j]=(I[i][j]-g+mod)%mod;
        }
    }

    for (int i=K; i>=0; i--) V[i]=1;
    for (int g=K; g>=0; g--) {
        for (int i=0; i<K; i++) for (int j=0; j<K; j++) A[i][j]=(I[i][j]+g*X[i][j])%mod;
        V[g]=inv(V[g])*det()%mod;
    }
    gau();
    cout << R[v];

    return 0;
}
