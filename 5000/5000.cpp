#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n;

const int X=17;
int seg[1<<X+1];
void update(int p, int x){p+=1<<X; while (p) seg[p]+=x, p>>=1;}
int sum(int s, int e) {
    int r=0; s+=1<<X; e+=1<<X;
    while (s<=e) {r+=seg[s]*(s&1)+seg[e]*(~e&1); ++s>>=1; --e>>=1;}
    return r;
}

signed main(){
    fastio;

    cin >> n;
    int s1=0, s2=0;
    for (int i=1; i<=n; i++) {int a; cin >> a; update(a, 1); s1+=sum(1, a-1);}
    fill(seg, seg+(1<<X+1), 0);
    for (int i=1; i<=n; i++) {int a; cin >> a; update(a, 1); s2+=sum(1, a-1);}
    cout << (((s1^s2)&1)?"Impossible":"Possible");

    return 0;
}
