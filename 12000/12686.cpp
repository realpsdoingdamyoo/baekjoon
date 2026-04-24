#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

int N, A[330][330];

int rnd() {
    return (1LL*rand()*rand()*rand()+(837593^rand())+1LL*rand()*rand()*233+1007)%mod;
}

int inv(int x) {
    int r=1, p=mod-2;
    while (p) {if (p&1) r=r*x%mod; x=x*x%mod; p>>=1;}
    return r;
}

int Mrank() {
    for (int i=1, id=1; i<=N; i++) {
        while (id<=N) {
            for (int j=i; j<=N; j++) if (A[j][id]) swap(A[i], A[j]);
            if (A[i][id]==0) id++; else break;
        }
        if (id>N) return i;

        for (int j=i+1; j<=N; j++) {
            int R=inv(A[i][id])*A[j][id]%mod;
            for (int k=id; k<=N; k++) A[j][k]=(A[j][k]-R*A[i][k]%mod+mod)%mod;
        }
        id++;
    }
    return N;
}

char S[20][20];
void solve(int t) {
    int X, Y; cin >> X >> Y; N=X*Y;
    for (int i=0; i<=N+1; i++) for (int j=0; j<=N+1; j++) S[i][j]=0;
    for (int i=1; i<=X; i++) for (int j=1; j<=Y; j++) cin >> S[i][j];
    for (int i=0; i<=N+1; i++) for (int j=0; j<=N+1; j++) A[i][j]=0;
    for (int i=1; i<=X; i++) for (int j=1; j<=Y; j++) {
        for (int x : {-1, 0, 1}) for (int y : {-1, 0, 1}) if (x||y) {
            if ((S[i][j]=='.' || S[i][j]=='K') && (S[i+x][j+y]=='.' || S[i+x][j+y]=='K')) {
                int a=(i-1)*Y+j, b=(i+x-1)*Y+j+y;
                A[a][b]=rnd(); A[b][a]=mod-A[a][b];
            }
        }
    }
    int g1=Mrank()/2;

    for (int i=0; i<=N+1; i++) for (int j=0; j<=N+1; j++) A[i][j]=0;
    for (int i=1; i<=X; i++) for (int j=1; j<=Y; j++) {
        for (int x : {-1, 0, 1}) for (int y : {-1, 0, 1}) if (x||y) {
            if (S[i][j]=='.' && S[i+x][j+y]=='.') {
                int a=(i-1)*Y+j, b=(i+x-1)*Y+j+y;
                A[a][b]=rnd(); A[b][a]=mod-A[a][b];
            }
        }
    }
    int g2=Mrank()/2;

    if (g1==g2) cout << "Case #" << t << ": B\n";
    else cout << "Case #" << t << ": A\n";
}

signed main() {
    fastio;

    int T; cin >> T;
    for (int i=1; i<=T; i++) solve(i);

    return 0;
}
