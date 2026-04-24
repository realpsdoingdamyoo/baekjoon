#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int N, K;
int A[100], B[100][100];
vector<int> C[100];

int pw[200]={1};

int cal(int l, int r) {
    for (int i=1; i<=K; i++) {
        C[i].clear();
        for (int j=l; j<=r; j++) {
            C[i].push_back(B[i][j]);
        }
    }

    int M=r-l+1, p=0;
    for (int i=1; i<=K; p++) {
        if (p>=M) break;
        for (int j=i; j<=K; j++) if (C[j][p]) {swap(C[i], C[j]); break;}
        if (C[i][p]==0) continue;
        for (int j=i+1; j<=K; j++) if (C[j][p]) {
            for (int k=0; k<M; k++) C[j][k]^=C[i][k];
        }
        i++;
    }

    vector<int> D;
    for (int i=l; i<=r; i++) D.push_back(!A[i]);

    for (int i=1; i<=K; i++) {
        int ch=0;
        for (int j=0; j<M; j++) if (C[i][j]) {
            if (D[j]==1) ch=1; break;
        }
        //cout << l << " " << r << ' ' << ch << "\n";
        if (!ch) continue;

        for (int j=0; j<M; j++) D[j]^=C[i][j];
    }

    int one=0;
    for (int i : D) one+=i;
    if (one) return 190;

    int cnt=0;
    for (int i=1; i<=K; i++) {
        one=0;
        for (int j=0; j<M; j++) one+=C[i][j];
        cnt+=!one;
    }

    return cnt;
}

signed main() {
    fastio;

    for (int i=1; i<=100; i++) pw[i]=pw[i-1]*2%MOD;

    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> A[i];

    for (int i=1; i<=K; i++) {
        int l, r; cin >> l >> r;
        for (int j=l; j<=r; j++) B[i][j]=1;
    }

    int ans=0;
    for (int i=1; i<=N; i++) for (int j=i; j<=N; j++) {
        ans=(ans+pw[cal(i, j)])%MOD;
    }
    cout << ans;


    return 0;
}
