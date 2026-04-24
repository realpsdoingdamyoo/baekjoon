#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N;
vector<array<int, 2>> lnk[202020];
int LZ[202020];
multiset<int> st[202020], S;
int Q;
array<int, 2> qry[202020];
int ans[202020];

void dfs(int p, int pre) {
    st[p].insert(0);
    if (lnk[p].size()==1 && p!=1) st[p].insert(0);
    for (array<int, 2> i : lnk[p]) if (i[0]!=pre) {
        dfs(i[0], p);
        int x=i[0];

        LZ[x]++;
        int tp=*prev(st[x].end());
        st[x].erase(prev(st[x].end()));
        st[x].insert(tp+i[1]-1);

        if (*st[x].begin()+LZ[x]<*st[p].begin()+LZ[p])
            while (st[x].size() && *st[x].begin()+LZ[x]<*st[p].begin()+LZ[p])
                st[x].erase(st[x].begin());
        else
            while (st[p].size() && *st[x].begin()+LZ[x]>*st[p].begin()+LZ[p])
                st[p].erase(st[p].begin());

        if (st[p].size()<st[x].size()) swap(st[p], st[x]), swap(LZ[p], LZ[x]);
        for (int j : st[x]) st[p].insert(j+LZ[x]-LZ[p]);
    }

    //cout << p << " / ";
    //for (int i : st[p]) cout << i+LZ[p] << ' ';
    //cout << "\n";
}

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c});
        lnk[b].push_back({a, c});
    }
    dfs(1, 0);

    for (int i : st[1]) S.insert(i+LZ[1]);

    //for (int i : S) cout << i << " "; cout << "\n";

    cin >> Q;
    for (int i=1; i<=Q; i++) {
        int a; cin >> a;
        qry[i]={a, i};
    }
    sort(qry+1, qry+Q+1);

    int s=1, U=0;
    for (int i=1; i<=Q; i++) {
        int x=qry[i][0];
        while (S.size()>=2) {
            int F=*prev(S.end()), SE=*prev(prev(S.end()));
            if (U+s*(F-SE)<=x) U+=s*(F-SE), s++, S.erase(S.find(F));
            else break;
        }
        if (S.size()==1) ans[qry[i][1]]=*S.begin();
        else {
            int F=*prev(S.end());
            ans[qry[i][1]]=F-(x-U)/s;
        }
    }

    for (int i=1; i<=Q; i++) cout << ans[i] << "\n";

    return 0;
}
