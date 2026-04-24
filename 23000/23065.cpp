#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=4e18;

int N, M;
vector<int> lnk[1010];

vector<int> D1(1010), D2(1010);
int p1=1, p2=1;

void dfs(int p, int x, vector<int>& d, int& c) {
    for (int i : lnk[p]) if (i!=x && lnk[i].size()>=2) d[i]=d[p]+1, dfs(i, p, d, c);
    if (d[p]>d[c]) c=p;
}

vector<int> ans;

int vis[1010];
void solve(int p) {
    vector<int> vec; vis[p]=1; ans.push_back(p);
    for (int i : lnk[p]) if (lnk[i].size()>=2 && !vis[i]) vec.push_back(i);
    for (int& i : vec) if (D1[i]+D2[i]==D2[p1]) swap(i, vec.back());
    for (int i : vec) {
        solve(i);
        if (i!=vec.back()) ans.push_back(p);
    }
}

signed main(){
    fastio;

    cin >> N >> M;
    if (N<=M) {cout << "NO"; return 0;}
    if (N==1) {cout << "YES\n1\n1"; return 0;}
    if (N==2) {cout << "YES\n2\n1 1"; return 0;}

    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }

    while (lnk[p2].size()==1) p1++, p2++;
    dfs(p2, 0, D2, p1); dfs(p1, 0, D1, p2); D2[p2]=0; dfs(p2, 0, D2, D2[N+1]);

    for (int i=1; i<=N; i++) if (lnk[i].size()>=2 && D1[i]+D2[i]!=D2[p1]) {
        int cnt=0;
        for (int j : lnk[i]) if (lnk[j].size()>=2) cnt++;
        if (cnt>1) {cout << "NO"; return 0;}
    }

    solve(p1);
    cout << "YES\n" << ans.size()*2 << "\n";
    for (int i : ans) cout << i << " ";
    if (ans.size()%2==0) reverse(ans.begin(), ans.end());
    for (int i : ans) cout << i << " ";

    return 0;
}
