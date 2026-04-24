#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, Q, V[202020], NX[202020], R[202020], U[202020], A[1010101];
vector<array<int, 3>> qry={{inf}};

set<array<int, 3>> st;

const int X=18;
int seg[1<<X+1];
void update(int p, int x) {
    p+=1<<X;
    while (p) seg[p]+=x, p>>=1;
}
int Find(int p, int& k) {
    if (p>=(1<<X)) return p-(1<<X);
    if (seg[p<<1]>=k) return Find(p<<1, k);
    k-=seg[p<<1]; return Find(p<<1|1, k);
}

void bl(int s, int e) {
    if (s>e) return;
    int r=min(e, NX[s]-1);
    st.insert({V[s], s, r}); update(V[s], r-s+1);
    bl(r+1, e);
}

signed main() {
    fastio;

    cin >> N >> Q;
    for (int i=1; i<=N; i++) cin >> V[i], R[V[i]]=i;
    for (int i=1, x, y; i<=Q; i++) cin >> x >> y, qry.push_back({min(x, N), y, i});
    sort(qry.begin(), qry.end(), [&](array<int, 3> a, array<int, 3> b){return a[0]>b[0];});

    while (qry.back()[0]==0) A[qry.back()[2]]=V[qry.back()[1]], qry.pop_back();

    V[N+1]=N+1;
    vector<int> s={N+1};

    for (int i=N; i>=1; i--) {
        while (V[s.back()]<V[i]) s.pop_back();
        NX[i]=s.back(); s.push_back(i);
    }

    bl(1, N/2); bl(N/2+1, N);

    int len=N;
    for (int t=1; t<=N; t++) {
        while (qry.back()[0]==t) {
            array<int, 3> x=qry.back();
            if (x[1]>len) A[x[2]]=U[x[1]];
            else {int p=Find(1, x[1]); A[x[2]]=V[R[p]+x[1]-1];}
            qry.pop_back();
        }
        while (len-((*prev(st.end()))[2]-(*prev(st.end()))[1]+1)>=N/2) {
            array<int, 3> x=*prev(st.end());
            for (int i=x[2]; i>=x[1]; i--) U[len--]=V[i];
            update(x[0], -x[2]+x[1]-1); st.erase(prev(st.end()));
        }
        if (len==N/2) continue;
        array<int, 3> x=*prev(st.end()); st.erase(prev(st.end()));
        int rc=len-N/2;
        bl(x[2]-rc+1, x[2]);
        x[2]-=rc; st.insert(x);
        update(x[0], -rc);
    }

    for (int i=1; i<=Q; i++) cout << A[i] << "\n";

    return 0;
}
