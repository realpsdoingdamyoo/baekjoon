#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int F[2020202], B[2020202];
int N;
int R[2020202];
int S[2020202];


signed main() {
    fastio;
    string s; cin >> s;
    N=s.length();
    for (int i=1; i<=N; i++) S[i]=s[i-1]=='-'?-1:s[i-1]-'0';

    for (int i=1, c=0; i<=N; i++) {
        if (S[i]==-1) c^=1;
        else (c==0?F[i]:B[i])++;
    }
    for (int i=1; i<=N; i++) F[i]+=F[i-1], B[i]+=B[i-1];

    for (int i=1, c=0; i<=N; i++) {
        if (S[i]==-1) c^=1;
        else if (c==0) {
            R[F[N]-F[i-1]]+=S[i]; R[0]-=S[i];
            R[F[i]+B[N]]+=S[i]; R[F[i]+B[i]]-=S[i];
        }
        else {
            R[B[N]-B[i-1]]+=S[i]; R[0]-=S[i];
            R[F[N]+B[i]]+=S[i]; R[F[i]+B[i]]-=S[i];
        }
    }
    for (int i=0; i<=N+3; i++) {
        int x=(R[i]+10*mod)/10-mod;
        R[i+1]+=x; R[i]-=x*10;
    }
    for (int i=N+3; i>=0; i--) {
        if (R[i]%9) R[i-1]+=R[i]%9*10;
        R[i]/=9;
    }
    for (int i=N+3, j=0; i>=0; i--) {
        j|=R[i];
        if (j) cout << R[i];
    }

    return 0;
}
