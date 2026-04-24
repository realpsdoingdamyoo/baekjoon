#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, A;
vector<int> lnk[202020];
int B[202020];

int CO[202020];

int DP[202020];
void dp(int p, int pre) {
    DP[p]=-B[p];
    for (int i : lnk[p]) if (i!=pre && !CO[i]) dp(i, p), DP[p]+=DP[i];
    DP[p]=max(DP[p], B[p]);
}


int S[202020];
void getsz(int p, int pre) {
    S[p]=1;
    for (int i : lnk[p]) if (i!=pre && !CO[i])
        getsz(i, p), S[p]+=S[i];
}

int getc(int p, int pre, int s) {
    for (int i : lnk[p]) if (i!=pre && !CO[i])
        if (S[i]>=s/2) return getc(i, p, s);
    return p;
}

int R[202020];
void solve(int p) {
    getsz(p, 0);
    int c=getc(p, 0, S[p]);

    int AS=0, MX=0;
    for (int i : lnk[c]) if (!CO[i]) {
        dp(i, c);
        AS+=DP[i]; MX=max(MX, DP[i]);
    }
    A=max(A, AS-B[c]); A=max(A, MX+B[c]);

    CO[c]=1;
    for (int i : lnk[c]) if (!CO[i]) solve(i);
}

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }
    for (int i=1; i<=N; i++) {
        char c; cin >> c;
        B[i]=c-'0';
    }

    solve(1);

    cout << A << "\n";

    return 0;
}
