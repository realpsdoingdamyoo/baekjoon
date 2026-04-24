#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
int V[110][110];
int B[200], P[4];
int W[1010101][4];
int X, Y;

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=0; i<=N+1; i++) for (int j=0; j<=N+1; j++) V[i][j]=1;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        cin >> V[i][j];
        if (V[i][j]==2) X=i, Y=j, V[i][j]=0;
    }

    B['W']=0; B['A']=1; B['S']=2; B['D']=3;
    for (char i=0; i<4; i++) {
        string p; cin >> p;
        if (p=="Down") P[i]=1;
        else if (p=="Stay") P[i]=3;
        else P[i]=2;
    }

    string s; cin >> s;
    for (int i=1; i<=M; i++) W[i][B[s[i-1]]]=1;

    for (int i=1; i<=M; i++) {
        for (int j=0; j<4; j++) {
            if (W[i-1][j]*2+W[i][j]==P[j]) {
                if (j==0 && V[X-1][Y]==0) X--;
                if (j==1 && V[X][Y-1]==0) Y--;
                if (j==2 && V[X+1][Y]==0) X++;
                if (j==3 && V[X][Y+1]==0) Y++;
            }
        }
    }
    cout << X << " " << Y << "\n";

    return 0;
}
