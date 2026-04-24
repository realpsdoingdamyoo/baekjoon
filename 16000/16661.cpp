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

void solve() {
    int X, Y; cin >> X >> Y; N=2*X+Y;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) A[i][j]=0;
    for (int i=1; i<=X; i++) {A[i][i+X]=rnd(); A[i+X][i]=mod-A[i][i+X];}
    for (int i=1; i<=X; i++) {
        string S; cin >> S;
        for (int j=1; j<=Y; j++) if (S[j-1]=='1') {
            A[i][2*X+j]=rnd();
            A[i+X][2*X+j]=rnd();
            A[2*X+j][i]=mod-A[i][2*X+j]; A[2*X+j][X+i]=mod-A[i+X][2*X+j];
        }
    }

    int g=N;
    for (int i=1, id=1; i<=N; i++) {
        while (id<=N) {
            for (int j=i; j<=N; j++) if (A[j][id]) swap(A[i], A[j]);
            if (A[i][id]==0) id++; else break;
        }
        if (id>N) {g=i; break;}

        for (int j=i+1; j<=N; j++) {
            int R=inv(A[i][id])*A[j][id]%mod;
            for (int k=id; k<=N; k++) A[j][k]=(A[j][k]-R*A[i][k]%mod+mod)%mod;
        }
        id++;
    }
    cout << g/2-X << "\n";
}

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
