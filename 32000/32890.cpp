#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
int A[303030];
vector<array<int, 2>> lnk[303030];
int C[303030][2];
int DP[303030][2], VIS[303030][2];

void DFS(int p, int x, int t) {
    if (VIS[p][x]==t) {
        cout << "infinity";
        exit(0);
    }
    if (VIS[p][x]) return;
    VIS[p][x]=t;
    for (array<int, 2> i : lnk[p]) if (i[1]==x) {
        DFS(i[0], x^1, t);
        DP[p][x]=max(DP[p][x], DP[i[0]][x^1]+1);
    }
    VIS[p][x]=t-1;
}

int D(int x, int a) {return x-(x-a+4)%4;}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<=N; i++) DP[i][0]=DP[i][1]=0;
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back({b, A[a]==A[b]});
        lnk[b].push_back({a, A[a]==A[b]});
    }

    for (int i=1; i<=N; i++) {
        DFS(i, 0, i*2);
        DFS(i, 1, i*2+1);
    }

    int R[4]={0, 0, 0, 0};
    for (int i=1; i<=N; i++) {
        if (A[i]==0) {
            for (int j=0; j<4; j++) {
                R[j]=max(R[j], D(DP[i][0], j)+1+DP[i][1]);
                R[j]=max(R[j], D(DP[i][1], (j+1)%4)+1+DP[i][0]);
            }
        }
        else {
            for (int j=0; j<4; j++) {
                R[j]=max(R[j], D(DP[i][0], (j+2)%4)+1+DP[i][1]);
                R[j]=max(R[j], D(DP[i][1], (j+3)%4)+1+DP[i][0]);
            }
        }
    }
    cout << *min_element(R, R+4)+1;

    return 0;
}
