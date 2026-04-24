#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int N, K, R=1;
string S, ans;
int kmp[1010101], id[1010101];

signed main(){
    fastio;

    cin >> S >> K; K--;
    N=S.length();

    for (int i=1, j=0; i<N; i++) {
        while (j && S[i]!=S[j]) j=kmp[j-1];
        if (S[i]==S[j]) kmp[i]=++j;
    }

    vector<array<int, 2>> v;

    for (int i=0; i<N; i++) if (!kmp[i]) {
        int k=0, j=i;
        while (j) j=kmp[j-1], k+=!kmp[j];
        R=R*(26-k)%mod; v.push_back({i, 26-k});
    }
    cout << R << "\n";

    reverse(v.begin(), v.end());
    for (array<int, 2> i : v) {
        id[i[0]]=K%i[1]; K/=i[1];
    }

    if (K){cout << "OVER"; return 0;}

    for (int i=0; i<N; i++) {
        if (kmp[i]) {ans+=ans[kmp[i]-1]; continue;}
        int c[26]={};
        int j=i, p=0;
        while (j) j=kmp[j-1], c[ans[j]-'a']=1;
        while (c[p]) p++;
        for (j=0; j<id[i]; j++) {p++; while (c[p]) p++;}
        ans+='a'+p;
    }
    cout << ans;


    return 0;
}
