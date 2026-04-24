#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=4e18;

int N, K, Q, A[101010];
int L[101010][20], R[101010][20];
vector<int> st;

signed main(){
    fastio;

    cin >> N >> K >> Q;
    for (int i=1; i<=N; i++) cin >> A[i];
    st={}; for (int i=1; i<=N; i++) {
        while (st.size() && A[st.back()]<=A[i]) R[st.back()][0]=i, st.pop_back();
        st.push_back(i);
    } R[N][0]=N;
    st={}; for (int i=N; i>=1; i--) {
        while (st.size() && A[st.back()]<=A[i]) L[st.back()][0]=i, st.pop_back();
        st.push_back(i);
    } L[1][0]=1;

    for (int j=1; j<20; j++) for (int i=1; i<=N; i++) {
        L[i][j]=min(L[L[i][j-1]][j-1], L[R[i][j-1]][j-1]);
        R[i][j]=max(R[L[i][j-1]][j-1], R[R[i][j-1]][j-1]);
    }

    for (int i=1, x, y; i<=Q; i++) {
        cin >> x >> y; if (x>y) swap(x, y);
        int r=x, l=y, ans=0;
        for (int j=19; j>=0; j--) {
            int g=max(R[x][j], R[r][j]);
            if (g<y) x=min(L[x][j], L[r][j]), r=g, ans+=1<<j;
        }
        for (int j=19; j>=0; j--) {
            int g=min(L[l][j], L[y][j]);
            if (r<g) y=max(R[y][j], R[l][j]), l=g, ans+=1<<j;
        }
        cout << ans << "\n";
    }

    return 0;
}
