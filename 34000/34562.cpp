#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
//const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, K;
int C[22][22], R[22];

vector<array<int, 2>> vec[101010];
int V[22][1050101], D[22][1050101];

int DP[101010];

int pc[1050101];

signed main(){
    fastio;

    for (int i=1; i<1<<20; i++) pc[i]=pc[i&(i-1)]+1;

    cin >> N >> M >> K;

    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) C[i][j]=K+1, R[i]=K+1;
    for (int i=1; i<=N; i++) for (int j=0; j<1<<N; j++) D[i][j]=K+1;
    for (int i=1; i<=M; i++) {
        int a, b, c; cin >> a >> b >> c;
        C[a][b]=C[b][a]=min(C[a][b], c);
    }

    vec[0].push_back({1, 1});
    for (int i=0; i<=K; i++) {
        for (array<int, 2> p : vec[i]) {
            if (V[p[0]][p[1]]++) continue;
            if (p[0]==1 && p[1]!=1) R[pc[p[1]]]=min(R[pc[p[1]]], i);
            else for (int j=1; j<=N; j++) if (i+C[p[0]][j]<=K) {
                if (i+C[p[0]][j]>=D[j][p[1]|(1<<j-1)]) continue;
                D[j][p[1]|(1<<j-1)]=i+C[p[0]][j];
                if (V[j][p[1]|(1<<j-1)]) continue;
                vec[i+C[p[0]][j]].push_back({j, p[1]|(1<<j-1)});
            }
        }
    }

    for (int i=2; i<=N; i++) {
        for (int j=R[i]; j<=K; j++) {
            DP[j]=max(DP[j-R[i]]+(i-1)*(i-1), DP[j]);
        }
    }

    cout << DP[K];

    return 0;
}
