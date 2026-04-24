#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int N;
int g[1010];
int X[1010], Y[1010], R[1010];
vector<array<int, 3>> vec;

int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
int Union(int a, int b) {
    a=Find(a); b=Find(b);
    g[a]=b; return a!=b;
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> X[i] >> Y[i] >> R[i];
    for (int i=1; i<=N; i++) g[i]=i;
    for (int i=1; i<=N; i++) for (int j=i+1; j<=N; j++) {
        double D=sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
        double R1=min(R[i], R[j]), R2=max(R[i], R[j]);
        if (D<=R1+R2) {vec.push_back({0, i, j}); continue;}
        double ret=0, th=acos((R2-R1)/D)*2, pi=acos(-1);
        ret+=sqrt(D*D-(R2-R1)*(R2-R1))*2;
        ret+=th*R1; ret+=(pi*2-th)*R2;
        vec.push_back({(int)(ret*1e8), i, j});
    }

    sort(vec.begin(), vec.end());

    int ans=0;
    for (array<int, 3> i : vec) {
        ans+=Union(i[1], i[2])*i[0];
    }

    cout.precision(10);
    cout << ans/1e8;

    return 0;
}
