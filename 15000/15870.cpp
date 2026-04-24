#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e5, inf=2e18;

int N, M, B[2050], V[2020][2020], U[11][2020][2020];
void chmax(int a, int b, int c, int d){U[a][b][c]=max(U[a][b][c], d);}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {char x; cin >> x; V[i][j]=(x=='#');}
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) V[i][j]+=V[i-1][j];
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) V[i][j]+=V[i][j-1];
    for (int i=0; i<11; i++) for (int j=1<<i; j<1<<i+1; j++) B[j]=i;

    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        int s=0, e=min(N-i, M-j);
        while (s<=e) {
            int m=s+e>>1;
            if (V[i+m][j+m]-V[i-1][j+m]-V[i+m][j-1]+V[i-1][j-1]==0) s=m+1;
            else e=m-1;
        }

        chmax(B[s], i, j, s*s);
        chmax(B[s], i, j+e-(1<<B[s])+1, s*s);
        chmax(B[s], i+e-(1<<B[s])+1, j, s*s);
        chmax(B[s], i+e-(1<<B[s])+1, j+e-(1<<B[s])+1, s*s);
    }

    for (int b=10; b>=1; b--) {
        for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
            chmax(b-1, i, j, U[b][i][j]);
            chmax(b-1, i+(1<<b-1), j, U[b][i][j]);
            chmax(b-1, i, j+(1<<b-1), U[b][i][j]);
            chmax(b-1, i+(1<<b-1), j+(1<<b-1), U[b][i][j]);
        }
    }

    int Q; cin >> Q;
    while (Q--) {
        int a, b; cin >> a >> b;
        cout << U[0][a][b] << "\n";
    }

    return 0;
}
