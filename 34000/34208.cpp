#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, Q;
int V[1010101], R[1010101];

int crs(array<int, 3> a, array<int, 3> b) {
    double ret=(a[2]-b[2]+0.0)/(b[1]-a[1]);
    return ceil(ret);
}

void DNC(int s, int e) {
    if (s==e){R[1]=max(R[1], V[s]); return;}

    int m=s+e>>1;
    vector<array<int, 3>> LC={{-inf, 0, 0}}, RC={{-inf, 0, 0}};

    int LS=0, RS=0;

    for (int i=m; i>=s; i--) {
        LS+=V[i]; array<int, 3> li={0, m-i+1, LS};
        while (LC.size()>=2 && crs(LC[LC.size()-2], LC.back())>=crs(LC.back(), li)) LC.pop_back();
        LC.push_back(li);
    }
    for (int i=m+1; i<=e; i++) {
        RS+=V[i]; array<int, 3> li={0, i-m, RS};
        while (RC.size()>=2 && crs(RC[RC.size()-2], RC.back())>=crs(RC.back(), li)) RC.pop_back();
        RC.push_back(li);
    }

    for (int i=LC.size()-1; i>=1; i--) LC[i][0]=crs(LC[i-1], LC[i]), LC[i][1]-=LC[i-1][1], LC[i][2]-=LC[i-1][2];
    for (int i=RC.size()-1; i>=1; i--) RC[i][0]=crs(RC[i-1], RC[i]), RC[i][1]-=RC[i-1][1], RC[i][2]-=RC[i-1][2];
    vector<array<int, 3>> C;
    for (array<int, 3> i : LC) C.push_back(i);
    for (array<int, 3> i : RC) C.push_back(i);
    sort(C.begin(), C.end());

    for (int i=1; i<C.size(); i++) C[i][1]+=C[i-1][1], C[i][2]+=C[i-1][2];
    for (array<int, 3> i : C) R[i[1]]=max(R[i[1]], i[2]);
    DNC(s, m); DNC(m+1, e);
}

signed main() {
    fastio;

    cin >> N >> Q;
    for (int i=1; i<=N; i++) cin >> V[i];
    for (int i=1; i<=N; i++) R[i]=-inf;
    DNC(1, N);

    vector<array<int, 3>> C;
    for (int i=1; i<=N; i++) if (R[i]!=-inf) {
        array<int, 3> li={0, i, R[i]};
        while (C.size()>=2 && crs(C[C.size()-2], C.back())>=crs(C.back(), li)) C.pop_back();
        C.push_back(li);
    }
    C[0][0]=-inf; for (int i=1; i<C.size(); i++) C[i][0]=crs(C[i-1], C[i]);

    for (int i=1; i<=Q; i++) {
        int x; cin >> x;
        array<int, 3> y=*prev(lower_bound(C.begin(), C.end(), array<int, 3>{x, inf, inf}));
        cout << x*y[1]+y[2] << '\n';
    }

    return 0;
}
