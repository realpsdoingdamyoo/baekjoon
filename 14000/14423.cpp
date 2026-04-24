#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n, m;
int ans[1010101];
int c[1010101];
vector<int> col[1010101];

const int X=20;
int seg[1<<X+1];
void update(int p, int x){
    p+=1<<X; seg[p]+=x; p>>=1;
    while(p) seg[p]=max(seg[p<<1], seg[p<<1|1]), p>>=1;
}

signed main(){
    fastio;

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> c[i];
        col[c[i]].push_back(i);
        update(c[i], 1);
    }
    for(int i=1; i<=m; i++) ans[i]=inf;

    for(int p=1; p<=m; p++){
        if(col[p].size()==0) continue;
        int cnt=col[p].size();
        for(int i : col[p]){
            update(c[i], -1);
            int j=i^1;
            if(1<=j && j<=n){
                update(c[j], -1);
                if(c[j]==c[i]) cnt--;
            }
        }
        ans[p]=min(ans[p], n-(int)col[p].size()-seg[1]);
        for(int i : col[p]){
            update(c[i], 1);
            int j=i^1;
            if(1<=j && j<=n){
                update(c[j], 1);
            }
        }
    }

    for(int p=1; p<=m; p++){
        if(col[p].size()==0) continue;
        int cnt=col[p].size();
        for(int i : col[p]){
            update(c[i], -1);
            int j=((i+1)^1)-1;
            if(1<=j && j<=n){
                update(c[j], -1);
                if(c[j]==c[i]) cnt--;
            }
        }
        ans[p]=min(ans[p], n-(int)col[p].size()-seg[1]);
        for(int i : col[p]){
            update(c[i], 1);
            int j=((i+1)^1)-1;
            if(1<=j && j<=n){
                update(c[j], 1);
            }
        }
    }

    int nop=inf;
    for(int i=1; i<n; i++){
        update(c[i], -1); update(c[i+1], -1);
        nop=min(nop, n-seg[1]);
        update(c[i], 1); update(c[i+1], 1);
    }
    update(c[1], -1); nop=min(nop, n-seg[1]); update(c[1], 1);
    update(c[n], -1); nop=min(nop, n-seg[1]); update(c[n], 1);

    for(int i=1; i<=m; i++){
        if(col[i].size()==0) ans[i]=min(ans[i], nop);
        cout << ans[i] << "\n";
    }



	return 0;
}
