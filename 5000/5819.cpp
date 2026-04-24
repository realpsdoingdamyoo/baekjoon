#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m, x;
vector<int> lnk[151515];
int go[303030], come[303030], rg[303030];
array<int, 2> c[2][303030];

signed main(){
    fastio;

    cin >> n >> m >> x;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        if(lnk[a].size()<2) lnk[a].push_back(b);
        if(lnk[b].size()<2) lnk[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        int p=lnk[i][0];
        go[i]=p+(lnk[p][0]==i)*n;
        come[go[i]]++;
    }

    for(int i=0; i<n; i++){
        int p=lnk[i].back();
        go[i+n]=p+(lnk[p][0]==i)*n;
        come[go[i+n]]++;
    }

    vector<int> vec, st;
    for(int i=0; i<n*2; i++) if(!come[i]) vec.push_back(i);
    for(int i=0; i<vec.size(); i++)
        if(!--come[go[vec[i]]]) vec.push_back(go[vec[i]]);

    for(int i=0; i<2*n; i++) if(come[i]) rg[go[i]]=i;
    for(int i=0; i<2*n; i++) c[0][i]=c[1][i]={inf, inf};

    for(int i=0; i<2; i++){
        int p=x+i*n, d=0;
        if(come[p]){
            while(1){
                c[i][p]={d++, 0}; p=rg[p];
                if(p==x+i*n) break;
            }
            while(1){
                c[i][p][1]=d; p=rg[p];
                if(p==x+i*n) break;
            }
        }
        else c[i][p]={0, inf};
    }

    while(vec.size()){
        int p=vec.back(); vec.pop_back();
        if(p!=x) c[0][p]={c[0][go[p]][0]+1, c[0][go[p]][1]};
        if(p!=x+m) c[1][p]={c[1][go[p]][0]+1, c[1][go[p]][1]};
    }

    int q; cin >> q;
    while(q--){
        int d, ans=0; cin >> d;
        for(int i=0; i<n; i++){
            if(c[0][i][0]<=d && (d-c[0][i][0])%c[0][i][1]==0) ans++;
            if(c[1][i][0]<=d && (d-c[1][i][0])%c[1][i][1]==0) ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}
