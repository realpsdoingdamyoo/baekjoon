#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=4e18;

int N=300;
int G[330][330], C[660];

int cw(int a, int b, int c, int d) {
    if (abs(a-c)<=1 || abs(b-d)<=1) return abs(a-c)+abs(b-d)==1;
    return (G[a][c]^G[b][d])==0;
}

signed main(){
    fastio;

    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) if (abs(i-j)>1) {
        fill(C, C+N*2, 0);
        for (int k=1; k<i; k++) C[G[k][j]]=1;
        for (int k=1; k<j; k++) C[G[i][k]]=1;
        while (C[G[i][j]]) G[i][j]++;
    }

    int T; cin >> T;
    while (T--) {
        int a, b, c, d, ans=0; cin >> a >> b >> c >> d;
        for (int i=a-1; i>=1 && (i!=c || b!=d); i--) ans+=cw(i, b, c, d);
        for (int i=b-1; i>=1 && (a!=c || i!=d); i--) ans+=cw(a, i, c, d);
        for (int i=c-1; i>=1 && (a!=i || b!=d); i--) ans+=cw(a, b, i, d);
        for (int i=d-1; i>=1 && (a!=c || b!=i); i--) ans+=cw(a, b, c, i);
        cout << ans << "\n";
    }

    return 0;
}
