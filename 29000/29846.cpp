#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N;
int P[202020], C[202020], L[202020], LF[202020];
set<int> lnk[202020], lef;

int pick(int p, int x) {
    while (p) {
        if (C[p]) return p;
        C[p]=x; L[p]--;
        lnk[P[p]].erase(lnk[P[p]].find(p));
        p=P[p];
    }
    return 1;
}

int pny(int p) {
    if (LF[p]) return p;
    return pny(*lnk[p].begin());
}

signed main(){
    cin >> N;
    for (int i=2; i<=N; i++) cin >> P[i];
    fill(LF+1, LF+N+1, 1);
    for (int i=N; i>=1; i--) {
        lnk[P[i]].insert(i);
        LF[P[i]]=0, L[i]+=LF[i], L[P[i]]+=L[i];
        if (LF[i]) lef.insert(i);
    }

    int x=*lef.begin();
    cout << "! " << x << endl;
    pick(x, 1); lef.erase(lef.find(x));

    while (lef.size()) {
        cin >> x; lef.erase(lef.find(x));
        int p=pick(x, 2);
        if (lnk[p].size()==0) x=*lef.begin();
        else x=pny(p); pick(x, 1);
        cout << "! " << x << endl;
        lef.erase(lef.find(x));
    }


    return 0;
}
