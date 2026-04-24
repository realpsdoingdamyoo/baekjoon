#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=9e18;

int ans;

int siz(array<int, 2> a, array<int, 2> b){return (b[0]-a[0])*(b[1]-a[1]);}
void dnc(int s, int e, int l, int r, vector<array<int, 2>>& L, vector<array<int, 2>>& R) {
    if (s>e) return;
    int op=l;
    int m=s+e>>1;
    for (int i=l; i<=r; i++) if (siz(L[m], R[op])<siz(L[m], R[i])) op=i;
    ans=max(ans, siz(L[m], R[op]));
    dnc(s, m-1, l, op, L, R); dnc(m+1, e, op, r, L, R);
}

void solve(vector<array<int, 3>> v) {
    if (v.size()==1) return;
    int n=v.size();
    vector<array<int, 3>> l=vector(v.begin(), v.begin()+n/2), r=vector(v.begin()+n/2, v.begin()+n);
    solve(l); solve(r);

    vector<array<int, 2>> L, R;
    int lmn=inf; for (array<int, 3> i : l) if (i[2]==0 && i[1]<lmn) L.push_back({i[0], i[1]}), lmn=i[1];
    reverse(r.begin(), r.end());
    int rmx=-inf; for (array<int, 3> i : r) if (i[2]==1 && i[1]>rmx) R.push_back({i[0], i[1]}), rmx=i[1];
    reverse(R.begin(), R.end());
    if (L.size()==0 || R.size()==0) return;
    dnc(0, L.size()-1, 0, R.size()-1, L, R);

}

signed main(){
    fastio;

    int N, M; cin >> N >> M;
    vector<array<int, 3>> v(N+M);
    for (int i=0; i<N; i++) cin >> v[i][0] >> v[i][1], v[i][2]=0;
    for (int i=N; i<N+M; i++) cin >> v[i][0] >> v[i][1], v[i][2]=1;
    sort(v.begin(), v.end()); solve(v);
    cout << ans;

    return 0;
}
