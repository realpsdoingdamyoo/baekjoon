#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
array<int, 2> V[101010], U[101010];
int DV[202020], DU[202020], R[202020];

void solve() {
    N=M=0; int n; cin >> n;
    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        if (a>b) V[++N]={a, b};
        else U[++M]={a, b};
    }
    multiset<int> s1, s2, s3;
    for (int i=1; i<=N; i++) s1.insert(V[i][0]), s1.insert(V[i][1]);
    for (int i=1; i<=M; i++) s2.insert(U[i][0]);
    sort(U+1, U+M+1, [&](array<int, 2> a, array<int, 2> b){return a[0]+a[1]>b[0]+b[1];});

    for (int i=1; i<=N*2; i++) {
        DV[i]=DV[i-1]+*prev(s1.end());
        s1.erase(prev(s1.end()));
    }
    for (int i=1; i<=M; i++) {
        DU[i*2-1]=DU[i*2-2]+*prev(s2.end());
        DU[i*2]=DU[i*2-2]+U[i][0]+U[i][1];
        s2.erase(s2.find(U[i][0]));
    }
    for (int S=0, i=1; i<=M; i++) {
        S+=U[i][0]+U[i][1]; s3.insert(U[i][1]);
        DU[i*2-1]=max(DU[i*2-1], S-*s3.begin());
    }

    for (int i=1; i<=N*2+M*2; i++) R[i]=0;

    for (int x : {0, 1}) for (int y : {0, 1}) {
        int i=x, j=y;
        while (i<=2*N && j<=2*M) {
            R[i+j]=max(R[i+j], DV[i]+DU[j]);
            if (i+2>2*N) j+=2;
            else if (j+2>2*M) i+=2;
            else if (DV[i+2]-DV[i]>DU[j+2]-DU[j]) i+=2;
            else j+=2;
        }
    }

    for (int i=1; i<=N*2+M*2; i++) cout << R[i] << " ";
    cout << "\n";
}

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
