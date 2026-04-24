#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, r, m;
int sp[505050][20], ans[505050], und[505050];
vector<int> lnk[505050], rup[505050], Rup[505050];

int dep[505050], nr[505050], sz[505050];
int in[505050], out[505050], cn;

void edfs(int p){
    in[p]=++cn;
    for(int i : lnk[p]){
        dep[i]=dep[p]+1;
        edfs(i); sz[p]+=sz[i]; nr[p]+=nr[i];
    } sz[p]++;
    out[p]=cn;
}

int up(int p, int d){
    for(int i=0; i<20; i++) if(d&(1<<i)) p=sp[p][i];
    return p;
}

const int X=19;
int seg[1<<X+1];
void update(int p, int x){
    p+=1<<X; seg[p]=x; p>>=1;
    while(p) seg[p]=seg[p<<1]+seg[p<<1|1], p>>=1;
}
int sum(int s, int e){
    s+=1<<X; e+=1<<X; int r=0;
    while(s<=e){
        if(s&1) r+=seg[s]; ++s>>=1;
        if(~e&1) r+=seg[e]; --e>>=1;
    } return r;
}
int cnt(int p){return sum(in[p], out[p]);}

void dfs(int p){
    for(int i : lnk[p]) dfs(i);
    update(in[p], 0);
    for(int i : Rup[p]) update(in[i], 1);

    int upr=n-sz[p];
    int ret=upr*(upr-1)/2;
    if(r<m) ret+=(sz[p]-nr[p])*upr;
    for(int i : rup[p]) ret+=cnt(i)*(cnt(i)-1)/2;

    ans[p]=ret;
}

signed main(){
    fastio;

    cin >> n >> r >> m;
    for(int i=2; i<=n; i++){
        cin >> sp[i][0];
        lnk[sp[i][0]].push_back(i);
    }
    for(int j=1; j<20; j++) for(int i=1; i<=n; i++)
        sp[i][j]=sp[sp[i][j-1]][j-1];
    for(int i=1; i<=n; i++) nr[i]++, nr[up(i, r+1)]--;
    for(int i=1; i<=n; i++) rup[up(i, r+1-(m+1)/2)].push_back(i);
    for(int i=1; i<=n; i++) Rup[up(i, r+1)].push_back(i);

    edfs(1);
    for(int i=1; i<=n; i++) update(in[i], 1);
    dfs(1);

    for(int i=1; i<=n; i++) cout << ans[i] << "\n";


    return 0;
}
