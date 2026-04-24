#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int N;
int V[505050];
int U[505050];
int S[505050];

bool bs(int K) {
    for (int i=1; i<=N; i++) U[i]=V[i]-min(i-1, N-i)*(K-1);
    int L=0, R=0;
    for (int i=1, C=N-1; i<=N/2; i++, C-=2) {
        R=max(R, (U[i]-(N-i)+C-1)/C);
    }
    for (int i=N, C=N-1; i>=(N+1)/2+1; i--, C-=2) {
        L=max(L, (U[i]-(i-1)+C-1)/C);
    }
    if (L+R<=K-2) L=K-1-R;
    if (L+R>K) return false;

    int MU=0;
    for (int i=1; i<=N; i++) U[i]=V[i]-L*(i-1)-R*(N-i), MU=max(MU, U[i]);
    if (L+R==K) return MU==0;

    //cout << K << " " << L << " " << R << "\n";
    //for (int i=1; i<=N; i++) cout << U[i] << " "; cout << "\n\n";

    for (int i=1; i<=N; i++) S[i]=0;
    for (int i=1; i<=N; i++) {
         S[1]++; S[N+1]--;
        if (U[i]>0) S[max(1LL, i-U[i]+1)]--, S[min(N+1, i+U[i])]++;
    }
    for (int i=1; i<=N; i++) {
        S[i]+=S[i-1];
        //if (K<=6) cout << S[i] << " ";
    }
    //cout << "\n";

    for (int i=1; i<=N; i++) if (S[i]==N) return true;

    return false;
}

void solve() {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> V[i];
    int S=0, E=2e18/(N-1)+2;
    while (S<=E) {
        int M=S+E>>1;
        if (bs(M)) E=M-1; else S=M+1;
    }
    cout << S << "\n";
}

signed main(){
    fastio;

    int T=1; cin >> T;
    while (T--) solve();

    return 0;
}
