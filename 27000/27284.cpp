#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, M, A[101010], B[101010];

const int X=17;
int seg[11][2<<X];
void update(int t, int p, int x) {
    p+=1<<X;
    while (p) seg[t][p]=max(seg[t][p], x), p>>=1;
}

int mxv(int t, int s, int e) {
    if (t==0) return (s==0?0:-inf);
    s+=1<<X; e+=1<<X; int r=0;
    while (s<=e) {
        if (s&1) r=max(r, seg[t][s]); ++s>>=1;
        if (~e&1) r=max(r, seg[t][e]); --e>>=1;
    } return r;
}

int DP[101010][11][2];

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> A[i] >> B[i];

    vector<int> st={0}; A[0]=inf;
    for (int i=1; i<=N; i++) {
        while (A[st.back()]<A[i]) st.pop_back();
        int p=st.back();
        for (int j=1; j<=M; j++) {
            DP[i][j][1]=max((A[p]==A[i]?DP[p][j][1]+B[i]:0), mxv(j-1, p, i-1)+B[i]);
            DP[i][j][0]=max({DP[i][j][1], DP[p][j][0], mxv(j-1, p, i-1)+B[i]});
            update(j, i, DP[i][j][0]);
        }
        st.push_back(i);
    }
    cout << DP[N][M][0];


    return 0;
}
