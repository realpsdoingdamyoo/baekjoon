#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N;
char V[55][55];

bool chk(int x, int sy, int ey, char c) {
    int nt=0;
    if (V[x][sy]!=c) {
        nt++;
        if (V[x][sy-1]!=c && V[x-1][sy]!=c && V[x+1][sy]!=c) return false;
    }
    if (V[x][ey]!=c) {
        nt++;
        if (V[x][ey+1]!=c && V[x-1][ey]!=c && V[x+1][ey]!=c) return false;
    }
    for (int i=sy+1; i<=ey-1; i++) if (V[x][i]!=c) {
        nt++;
        if (V[x-1][i]!=c && V[x+1][i]!=c) return false;
    }
    return nt<=1;
}

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin >> V[i][j];

    int ans=0;
    for (int i=1; i<=N; i++) for (int j=i+1; j<=N; j++) for (int x=1; x<=N; x++) for (char c : "CPZY")
        if (chk(x, i, j, c)) ans=max(ans, j-i+1);
    for (int i=1; i<=N; i++) for (int j=i; j<=N; j++) swap(V[i][j], V[j][i]);
    for (int i=1; i<=N; i++) for (int j=i+1; j<=N; j++) for (int x=1; x<=N; x++) for (char c : "CPZY")
        if (chk(x, i, j, c)) ans=max(ans, j-i+1);
    cout << ans;

    return 0;
}
