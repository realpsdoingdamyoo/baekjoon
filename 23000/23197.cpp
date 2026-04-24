#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n, l;
array<int, 2> v[3030];
vector<array<int, 4>> vec;
int V[3030], L[3030];

double dist(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    int s=abs(a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0]);
    int d=(a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    return s/sqrt(d);
}

void solve() {
    vec.clear();
    cin >> n >> l;
    for (int i=1; i<=n; i++) cin >> v[i][0] >> v[i][1];
    sort(v+1, v+n+1);

    for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++)
        vec.push_back({i, j, v[j][0]-v[i][0], v[j][1]-v[i][1]});
    sort(vec.begin(), vec.end(), [&](array<int, 4> a, array<int, 4> b){
        if (a[2]*b[3]==b[2]*a[3]) return a[0]*n+a[1]<b[0]*n+b[1];
        return a[2]*b[3]>b[2]*a[3];
    });

    for (int i=1; i<=n; i++) L[i]=V[i]=i;

    int ans=1;
    for (array<int, 4> li : vec) {
        swap(L[li[0]], L[li[1]]);
        swap(V[L[li[0]]], V[L[li[1]]]);
        int s1=1, e1=min(L[li[0]], L[li[1]])-1;
        while (s1<=e1) {
            int m=s1+e1>>1;
            if (dist(v[li[0]], v[li[1]], v[V[m]])>l) s1=m+1; else e1=m-1;
        }
        ans=max(ans, 2+(min(L[li[0]], L[li[1]])-s1));
        //cout << li[0] << " " << li[1] << " " << min(L[li[0]], L[li[1]]) << " " << s1 << "\n";

        int s2=max(L[li[0]], L[li[1]])+1, e2=n;
        while (s2<=e2) {
            int m=s2+e2>>1;
            if (dist(v[li[0]], v[li[1]], v[V[m]])>l) e2=m-1; else s2=m+1;
        }
        ans=max(ans, 2+(e2-max(L[li[0]], L[li[1]])));
        //cout << li[0] << " " << li[1] << " " << e2 << " " << max(L[li[0]], L[li[1]]) << "\n";
    }
    cout << ans << "\n";
}

signed main() {
    fastio;

    solve();

    return 0;
}
