#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=12e17;

int N, M, A[1010], D[1010], O[1010], L[1010][1010];
vector<int> lnk[1010];

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b; D[a]++; D[b]++;
        lnk[a].push_back(b); lnk[b].push_back(a); L[a][b]=L[b][a]=1;
    }

    for (int i=N; i>=1; i--) {
        int x=0;
        for (int j=1; j<=N; j++) if (!O[j] && (!x || D[j]<D[x])) x=j;
        A[i]=x; O[x]=1; for (int j : lnk[x]) if (!O[j]) D[j]--;
    }

    vector<int> ans={A[1], A[2]};

    for (int i=3; i<=N; i++) {
        int p=A[i]; vector<int> wl;
        int s=ans.size();
        for (int j=0; j<s; j++) {
            if (L[p][ans[j]] && wl.size()<2) wl.push_back(j);
            if (L[p][ans[j]] && L[p][ans[(j+1)%s]]) {ans.insert(ans.begin()+j+1, p); break;}
        }
        if (ans.size()<i) {
            vector<int> vec=vector(ans.begin()+wl[0]+1, ans.begin()+wl[1]);
            ans.erase(ans.begin()+wl[0]+1, ans.begin()+wl[1]);
            ans.insert(ans.begin()+wl[0]+1, p);

            s=ans.size();
            for (int j=0; j<s; j++) if (L[vec[0]][ans[j]] && L[vec.back()][ans[(j+1)%s]]) {
                for (int k : vec) ans.push_back(k);
                rotate(ans.begin()+j+1, ans.begin()+s, ans.end()); break;
            }
        }

    }
    cout << "0\n";
    for (int i : ans) cout << i << " ";


    return 0;
}
