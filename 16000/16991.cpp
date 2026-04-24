#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N, X[20], Y[20];
double dist[20][20];
double DP[20][101010];

signed main(){
    fastio;

    cin >> N;
    for (int i=0; i<N; i++) cin >> X[i] >> Y[i];
    for (int i=0; i<N; i++) for (int j=0; j<N; j++)
        dist[i][j]=sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));

    for (int i=0; i<N; i++) for (int j=0; j<1<<N; j++) DP[i][j]=inf; DP[0][1]=0;
    for (int j=0; j<1<<N; j++) for (int i=0; i<N; i++) for (int p=0; p<N; p++)
        if (j&(1<<i) && j&(1<<p)) DP[p][j]=min(DP[p][j], DP[i][j^(1<<p)]+dist[i][p]);

    double ans=inf;
    for (int i=0; i<N; i++) ans=min(ans, DP[i][(1<<N)-1]+dist[0][i]);
    cout.precision(10);
    cout << ans;

    return 0;
}
