#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n;
vector<int> v, u, V, U, A;

int Win() {
    int lf=0, ret=0;
    int p=U.size()-1;
    for (int i=V.size()-1; i>=0; i--) {
        while (p>=0 && U[p]>V[i]) p--, lf++;
        if (lf) ret++, lf--;
    } return ret;
}

signed main() {
    fastio;

    cin >> n;
    v.resize(n); u.resize(n);
    for (int& i : v) cin >> i;
    for (int& i : u) cin >> i;
    V=v; U=u; A.resize(n);
    sort(V.begin(), V.end());
    sort(U.begin(), U.end());

    int ans=Win();
    for (int i=0; i<n; i++) {
        int s=0, e=U.size()-1;

        if (U.back()>v[i]) {
            int x=upper_bound(U.begin(), U.end(), v[i])-U.begin();
            V.erase(lower_bound(V.begin(), V.end(), v[i]));
            int ux=U[x]; U.erase(lower_bound(U.begin(), U.end(), U[x]));
            if (Win()+1==ans) s=x; else e=x-1;

            V.insert(lower_bound(V.begin(), V.end(), v[i]), v[i]);
            U.insert(lower_bound(U.begin(), U.end(), ux), ux);
        }

        while (s<=e) {
            int m=s+e>>1;
            V.erase(lower_bound(V.begin(), V.end(), v[i]));
            int ux=U[m];
            U.erase(lower_bound(U.begin(), U.end(), U[m]));
            if ((v[i]<ux)+Win()==ans) s=m+1; else e=m-1;
            V.insert(lower_bound(V.begin(), V.end(), v[i]), v[i]);
            U.insert(lower_bound(U.begin(), U.end(), ux), ux);
        }
        A[i]=U[e];
        V.erase(lower_bound(V.begin(), V.end(), v[i]));
        U.erase(lower_bound(U.begin(), U.end(), U[e]));
        if (A[i]>v[i]) ans--;
    }

    for (int i : A) cout << i << " ";

    return 0;
}
