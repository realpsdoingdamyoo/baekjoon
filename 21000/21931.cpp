#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, U[4040];
array<int, 2> V[2020];
double R[2020][2020], D[4040][4040], F[2020][2020];
int op[4040][4040];

int ccw(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
}

double dist(array<int, 2> a, array<int, 2> b) {
    return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1], U[i]=i;
    sort(U+1, U+N+1, [&](int a, int b){return atan2(V[a][1], V[a][0])<atan2(V[b][1], V[b][0]);});
    for (int i=1; i<=N; i++) U[i+N]=U[i];

    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        if (i!=j) R[i][j]=inf;
    }

    for (int ii=1; ii<=N; ii++) {
        int i=U[ii];
        vector<int> st={i};
        for (int j=1; j<N; j++) {
            int p=U[(ii-j+N-1)%N+1];
            if (ccw(V[i], {0, 0}, V[p])<0) break;
            while (st.size()>=2 && ccw(V[st[st.size()-2]], V[st.back()], V[p])<0) st.pop_back();
            R[i][p]=R[i][st.back()]+dist(V[st.back()], V[p]);
            st.push_back(p);
        }
        st={i};
        for (int j=1; j<N; j++) {
            int p=U[(ii+j-1)%N+1];
            if (ccw(V[i], {0, 0}, V[p])>0) break;
            while (st.size()>=2 && ccw(V[st[st.size()-2]], V[st.back()], V[p])>0) st.pop_back();
            R[i][p]=R[i][st.back()]+dist(V[st.back()], V[p]);
            st.push_back(p);
        }
    }


    for (int i=1; i<=N*2; i++) op[i][i]=i;
    for (int l=2; l<=N+1; l++) for (int i=1; i+l-1<=N*2; i++) {
        int j=i+l-1;
        for (int p=op[i][j-1]; p<=op[i+1][j]; p++)
            if (D[i][j]<R[U[(i-1)%N+1]][U[(p-1)%N+1]]+R[U[(p-1)%N+1]][U[(j-1)%N+1]]) D[i][j]=R[U[(i-1)%N+1]][U[(p-1)%N+1]]+R[U[(p-1)%N+1]][U[(j-1)%N+1]], op[i][j]=p;
        D[(i-1)%N+1][(j-1)%N+1]=max(D[(i-1)%N+1][(j-1)%N+1], D[i][j]);
    }

    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) F[U[i]][U[j]]=D[i][j];
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) F[i][j]=max(F[i][j], F[j][i]);

    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) F[i][j]+=F[i-1][j];
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) F[i][j]+=F[i][j-1];

    int Q; cin >> Q;
    cout.precision(12);
    for (int i=1; i<=Q; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << (F[b][d]-F[a-1][d]-F[b][c-1]+F[a-1][c-1])/(b-a+1)/(d-c+1) << "\n";
    }

    return 0;
}
