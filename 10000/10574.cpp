#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int F[200];
int A[200];

void solve(vector<string> vec) {
    if (vec.size()==0) {
        cout << "no winner";
        return;
    }

    fill(A, A+200, 0); fill(F, F+200, 0);
    for (string i : vec) for (char c : i) A[c]=1;

    for (string& i : vec) F[i[0]]++;

    int M=1e6;
    for (int i='A'; i<='Z'; i++) if (F[i]>vec.size()/2) {
        cout << (char)i; return;
    }
    for (int i='A'; i<='Z'; i++) if (A[i]) M=min(M, F[i]);
    vector<string> ret;
    for (string& i : vec) {
        string tc;
        for (char c : i) if (F[c]!=M) tc+=c;
        if (tc!="") ret.push_back(tc);
    }

    for (int i='A'; i<='Z'; i++) if (A[i] && F[i]==M) cout << (char)i;
    cout << " -> ";
    solve(ret);
}

signed main(){
    fastio;

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<string> st(N);
        for (string& i : st) cin >> i;
        solve(st);
        cout << "\n";
    }

    return 0;
}
