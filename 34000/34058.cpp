#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n, m;
int v[505][505];
int pfn[505], sfx[505];

const int X=9;
int seg[505][1<<X+1];
void update(int t, int s, int e, int x){
    s+=1<<X; e+=1<<X;
    while(s<=e){
        seg[t][s]=max(seg[t][s], x);
        seg[t][e]=max(seg[t][e], x);
        ++s>>=1; --e>>=1;
    }
}
int Max(int t, int p){
    p+=1<<X; int r=-inf;
    while(p) r=max(r, seg[t][p]), p>>=1;
    return r;
}

signed main(){
    fastio;

    cin >> n >> m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        cin >> v[i][j];
        v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
    }

    for(int i=1; i<=n; i++) for(int j=1; j<(1<<X+1); j++) seg[i][j]=-inf;

    for(int i=1; i<=m; i++) for(int j=i; j<=m; j++){
        for(int k=1; k<=n; k++) pfn[k]=sfx[k]=0; sfx[n+1]=-inf;
        for(int k=1; k<=n; k++) pfn[k]=min(pfn[k-1], v[k][j]-v[k][i-1]);
        for(int k=n; k>=1; k--) sfx[k]=max(sfx[k+1], v[k][j]-v[k][i-1]);

        for(int k=1; k<=n; k++){
            update(k, i, j, sfx[k]-pfn[k-1]);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cout << Max(i, j) << " ";
        cout << "\n";
    }

	return 0;
}
