#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=9e18;

int ans=inf;

int dist(array<int, 2> a, array<int, 2> b) {
    return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
}

void solve(vector<array<int, 2>> v) {
    if (v.size()<=1) return;
    int n=v.size();
    solve(vector(v.begin(), v.begin()+n/2)); solve(vector(v.begin()+n/2, v.end()));
    int my=v[n/2][0];
    vector<array<int, 2>> mv;
    for (array<int, 2> i : v) if ((i[0]-my)*(i[0]-my)<=ans) mv.push_back(i);
    sort(mv.begin(), mv.end(), [&](array<int, 2> a, array<int, 2> b){return a[1]<b[1];});

    for (int i=0; i<mv.size(); i++) for (int j=i+1; ans && j<mv.size() && (mv[j][1]-mv[i][1])*(mv[j][1]-mv[i][1])<=ans; j++)
        ans=min(ans, dist(mv[i], mv[j]));
}

signed main(){
    fastio;

    int N; cin >> N;
    vector<array<int, 2>> vec(N);
    for (array<int, 2>& i : vec) cin >> i[0] >> i[1];
    sort(vec.begin(), vec.end());
    solve(vec);
    cout << ans;

    return 0;
}
