#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=4e18;

int M, A[2020202], G[2020202];
int D[505050], C[2020202];

int inv(int N, int P) {
    int R=1, p=P-2;
    while (p) {
        if (p&1) R=R*N%P;
        N=N*N%P; p>>=1;
    }
    return R;
}

vector<int> solve(int N, vector<int> V) {
    if (N==1) return V;

    if (D[N]!=N) {
        int P=D[N], Q=N/D[N];
        vector<int> U;
        for (int i=2*P*Q-P*2; i>=0; i-=P) {
            vector<int> X=solve(P, vector<int>(V.begin()+i, V.end()));
            unordered_set<int> st;

            U.push_back(++M);
            for (int j : X) st.insert(j), A[M]+=A[j], G[j]=M;
            A[M]/=P;

            for (int j=V.size()-1; j>=i; j--) if (st.find(V[j])!=st.end())
                swap(V[j], V.back()), V.pop_back();
        }

        return solve(Q, U);
    }

    sort(V.begin(), V.end(), [&](int a, int b){return A[a]%N<A[b]%N;});

    for (int i=0; i<N-1; i++) if (A[V[i]]%N==A[V[i+N-1]]%N)
        return vector<int>(V.begin()+i, V.begin()+i+N);

    vector<int> L(N, 0), T(N, 0); L[0]=1; T[0]=-1;

    int S=0;
    for (int i=0; i<N; i++) S=(S+N-A[V[i]]%N)%N;

    for (int i=0, X=0; i<N-1; i++) {
        int D=(N+A[V[i+N]]%N-A[V[i]]%N)%N;
        while (L[X]) X++;
        int s=0, e=X*inv(D, N)%N;

        while (s<=e) {
            int m=s+e>>1;
            if (L[m*D%N]) s=m+1;
            else e=m-1;
        }

        L[s*D%N]=1; T[s*D%N]=i;
    }

    vector<int> ret={V[N-1]};

    for (int i=N-2; i>=0; i--) {
        if (T[S]==i) ret.push_back(V[i+N]), S=(S-A[V[i+N]]%N+A[V[i]]%N+N)%N;
        else ret.push_back(V[i]);
    }

    return ret;
}

signed main(){
    fastio;

    int N;
    cin >> N; M=N*2-1;

    for (int i=1; i<=N; i++) D[i]=i;
    for (int i=2; i<=N; i++) for (int j=i; j<=N; j+=i) D[j]=min(D[j], D[i]);

    vector<int> V;
    for (int i=1; i<=M; i++) V.push_back(i), cin >> A[i];
    for (int i=1; i<=M*2; i++) G[i]=i;

    vector<int> ans=solve(N, V);
    for (int i : ans) C[i]=1;

    for (int i=1; i<=N*2-1; i++) {
        int p=i;
        while (G[p]!=p) p=G[p];
        if (C[p]) cout << A[i] << " ";
    }

    return 0;
}
