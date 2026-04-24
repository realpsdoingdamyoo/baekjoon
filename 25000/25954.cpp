#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int N, M, R, ih[7070][7070], iv[7070][7070];
string A, B;

signed main(){
    fastio;

    cin >> A >> B;
    N=A.length(); M=B.length(); A=" "+A; B=" "+B;

    for (int i=0; i<=N; i++) for (int j=1; j<=M; j++)
        if (i==0) ih[i][j]=j, iv[i][j]=0;
        else if (A[i]==B[j]) ih[i][j]=iv[i][j-1], iv[i][j]=ih[i-1][j];
        else ih[i][j]=max(ih[i-1][j], iv[i][j-1]), iv[i][j]=min(ih[i-1][j], iv[i][j-1]);
    for (int t=1; t<=N; t++) for (int k=1; k<=M; k++) R+=(M-k+1)*max(0LL, k-ih[t][k]);
    cout << R;

    return 0;
}
