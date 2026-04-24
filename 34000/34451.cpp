#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main(){

    int N, M; cin >> N;
    char S[50]; for (int i=1; i<=N; i++) cin >> S[i];
    cin >> M;
    vector<array<int, 2>> v;
    while (M--) {
        int x, a=0; char c; cin >> x;
        for (int i=1; i<=N; i++) cin >> c, a+=(c==S[i]);
        v.push_back({x, a});
    }

    string s; cin >> s;
    if (s=="STUDENT_ID_ASC") sort(v.begin(), v.end(), [&](array<int, 2> a, array<int, 2> b){return a[0]<b[0];});
    if (s=="STUDENT_ID_DESC") sort(v.begin(), v.end(), [&](array<int, 2> a, array<int, 2> b){return a[0]>b[0];});
    if (s=="GRADE_ASC") sort(v.begin(), v.end(), [&](array<int, 2> a, array<int, 2> b){return a[1]*mod+a[0]<b[1]*mod+b[0];});
    if (s=="GRADE_DESC") sort(v.begin(), v.end(), [&](array<int, 2> a, array<int, 2> b){return a[1]*mod-a[0]>b[1]*mod-b[0];});
    for (array<int, 2> i : v) cout << i[0] << " " << i[1] << '\n';

    return 0;
}
