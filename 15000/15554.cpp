#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main(){
    fastio;
    int n; cin >> n;
    vector<array<ll, 2>> v(n);
    vi njh1(n), njh2(n);
    for(int i=0; i<n; i++) cin >> v[i][0] >> v[i][1];
    sort(v.begin(), v.end());

    ll njh=v[0][1], bg=0, mnbg=0, ans=v[0][1];
    for(int i=1; i<n; i++){
        njh=njh+v[i][1]-v[i][0]+v[i-1][0];
        bg=bg+v[i-1][1]-v[i][0]+v[i-1][0];
        mnbg=min(bg, mnbg);
        ans=max(ans, njh-mnbg);
    }

    cout << ans << endl;
    return 0;
}
