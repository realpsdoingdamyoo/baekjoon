#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, Q;
vector<int> lnk[303030];

int R1, R2, R;
int dist[2][303030];
void dfs(int x, int p, int pre) {
    for (int i : lnk[p]) if (i!=pre) {
        dist[x][i]=dist[x][p]+1; dfs(x, i, p);
    }
}

int D[303030];
int P[303030];
int F[303030];

vector<int> C[303030];
vector<int> CS;

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }

    dfs(1,  1, 0); for (int i=1; i<=N; i++) if (dist[1][i]>dist[1][R1]) R1=i;
    dfs(0, R1, 0); for (int i=1; i<=N; i++) if (dist[0][i]>dist[0][R2]) R2=i;
    dist[1][R2]=0; dfs(1, R2, 0); R=dist[0][R2];

    for (int i=1; i<=N; i++) if (dist[0][i]+dist[1][i]==R) D[dist[0][i]]=i;
    for (int i=1; i<=N; i++) {
        int X=dist[0][i]-(dist[0][i]+dist[1][i]-R)/2;
        P[i]=X; F[X]=max(F[X], dist[0][i]-dist[0][D[X]]);
    }

    for (int i=0; i<=R; i++) {
        C[F[i]].push_back(i);
        CS.push_back(F[i]);
    }

    sort(CS.begin(), CS.end());
    CS.erase(unique(CS.begin(), CS.end()), CS.end());

    cin >> Q;
    for (int i=1; i<=Q; i++) {
        int a, b, ret=0; cin >> a >> b;
        int A=P[a], B=P[b];
        if (P[a]>P[b]) swap(a, b), swap(A, B);
        int da=dist[0][a]-A, db=dist[0][b]-B;
        int M=(A-da+B+db)/2;

        ret=max(ret, dist[0][a]*dist[0][b]);
        ret=max(ret, dist[1][a]*dist[1][b]);
        for (int j : CS) {
            if (C[j][0]<M) {
                int l=*prev(lower_bound(C[j].begin(), C[j].end(), M));
                if (A<=l && l<=B) ret=max(ret, (da+l-A+j)*(db+B-l+j));
            }
            if (C[j].back()>=M) {
                int r=*lower_bound(C[j].begin(), C[j].end(), M);
                if (A<=r && r<=B) ret=max(ret, (da+r-A+j)*(db+B-r+j));
            }
        }
        cout << ret << "\n";
    }

    return 0;
}
