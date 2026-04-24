#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, P=1;
int DP[1010101]={1, 1}, S[1010101]={1, 2};

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<N; i++) P=P*2%1999; P--;
    for (int i=2; i<N; i++) DP[i]=DP[i-1]*2%1999, S[i]=(S[i-1]+DP[i])%1999;
    for (int i=N; i<=M; i++) DP[i]=(S[i-1]-(i==N?0:S[i-N-1])+DP[i-N]*P+1999)%1999, S[i]=(S[i-1]+DP[i])%1999;
    cout << DP[M];

    return 0;
}
