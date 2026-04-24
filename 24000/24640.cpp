#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

array<int, 27> trie[606060];
int pv=1;

int N, K, R;

int dfs(int p) {
    priority_queue<int> ret; int sum=trie[p][26];
    for (int i=0; i<26; i++) if (trie[p][i]) {
        int x=dfs(trie[p][i]);
        ret.push(x); sum+=x;
    }

    while (sum>K) {sum-=ret.top(); ret.pop(); R++;}
    return sum;
}

signed main(){
    fastio;

    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        string s; cin >> s;
        int p=1;
        for (char c : s) {
            int& x=trie[p][c-'a'];
            p=x=x?x:++pv;
        }
        trie[p][26]=1;
    }

    cout << R+!!dfs(1);

    return 0;
}
