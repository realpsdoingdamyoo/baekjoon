#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, S, Q;
int V[202020], S1[202020], Si[202020];
int F[202020];
int L[202020], R[202020], A[202020];

int g(int l, int x) {
    l=max(l, x-F[x]);
    return x*(S1[x]-S1[l-1])-(Si[x]-Si[l-1]) + (Si[2*x-l]-Si[x-1])-x*(S1[2*x-l]-S1[x-1]) + (S-(S1[2*x-l]-S1[l-1]))*(x-l+1);
}

void dnc(int l, int r, vector<array<int, 3>> vec) {
    if (vec.size()==0) return;
    int m=vec.size()/2, p=vec[m][0], x=l;
    for (int i=l; i<=r; i++) if (g(p, i)>g(p, x)) x=i;
    A[vec[m][2]]=max(A[vec[m][2]], g(p, x));
    dnc(l, x, vector<array<int, 3>>(vec.begin(), vec.begin()+m));
    dnc(x, r, vector<array<int, 3>>(vec.begin()+m+1, vec.end()));
}


void DFS(int l, int r, vector<array<int, 3>> vec) {
    vector<array<int, 3>> ct, lvc, rvc; int m=l+r>>1;
    for (array<int, 3> i : vec) {
        if (i[0]<=l && r<=i[1]) ct.push_back(i);
        else if (i[0]<=r || l<=i[1]) {
            if (i[0]<=m) lvc.push_back(i);
            if (m<i[1]) rvc.push_back(i);
        }
    }

    sort(ct.begin(), ct.end());
    dnc(l, r, ct);

    if (l!=r) DFS(l, m, lvc), DFS(m+1, r, rvc);
}

signed main(){
    fastio;

    cin >> N >> S;
    for (int i=1; i<=N; i++) cin >> V[i]; V[0]=V[N+1]=inf;
    cin >> Q;
    for (int i=1; i<=Q; i++) cin >> L[i] >> R[i];

    for (int T=1; T<=2; T++) {
        for (int i=1; i<=N; i++) S1[i]=V[i]+S1[i-1], Si[i]=V[i]*i+Si[i-1];
        for (int i=1; i<=N; i++) {
            int s=0, e=min(i-1, N-i);
            while (s<=e) {
                int m=s+e>>1;
                if (S1[i+m]-S1[i-m-1]>S) e=m-1;
                else s=m+1;
            } F[i]=e;
        }

        vector<array<int, 3>> vec;
        for (int i=1; i<=Q; i++) vec.push_back({L[i], L[i]+R[i]>>1, i});
        DFS(1, N, vec);

        reverse(V+1, V+N+1);
        for (int i=1; i<=Q; i++) L[i]=N+1-L[i], R[i]=N+1-R[i], swap(L[i], R[i]);
    }

    for (int i=1; i<=Q; i++) cout << A[i] << "\n";

    return 0;
}
