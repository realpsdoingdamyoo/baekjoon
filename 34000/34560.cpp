#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N;
string X[3030];
int P[3030], A[3030], S[3030];
int W[3030][3030];
int L[3030];

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> X[i] >> P[i] >> A[i] >> S[i];

    for (int i=1; i<=N; i++) for (int j=i+1; j<=N; j++) {
        int K=0;
        if (P[i]>P[j]) K++; if (P[i]<P[j]) K--;
        if (A[i]>A[j]) K++; if (A[i]<A[j]) K--;
        if (S[i]>S[j]) K++; if (S[i]<S[j]) K--;
        if (K>0) K=1; if (K<0) K=-1;
        W[i][j]=K; W[j][i]=-K;
    }

    vector<int> st;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) if (i!=j)
            if (W[i][j]==-1) L[i]++;
        if (L[i]==0) st.push_back(i);
    }

    vector<string> vec;
    for (int i=1; i<=N; i++) if (L[i]==0) vec.push_back(X[i]);
    sort(vec.begin(), vec.end());

    int OC=0;
    while (st.size()) {
        int p=st.back(); st.pop_back(); OC++;
        for (int i=1; i<=N; i++) if (i!=p) {
            if (W[p][i]==1) {
                L[i]--;
                if (L[i]==0) st.push_back(i);
            }
        }
    }

    if (OC<N) {
        cout << "Paradoxe Absurdo";
        return 0;
    }

    for (string i : vec) cout << i << "\n";


    return 0;
}
