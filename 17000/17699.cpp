#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e15;

int l[505050], r[505050];
int lc[505050], rc[505050];
vector<int> k[505050];

bool isin(int s, int e, int key){
    vector<int>::iterator st=lower_bound(k[key].begin(), k[key].end(), s);
    vector<int>::iterator en=upper_bound(k[key].begin(), k[key].end(), e);
    return st!=en;
}

const int X=19;
int minseg[1<<X+1];
int maxseg[1<<X+1];

void minu(int p, int x){
    p+=1<<X; minseg[p]=x; p>>=1;
    while(p) minseg[p]=min(minseg[p<<1], minseg[p<<1|1]), p>>=1;
}

void maxu(int p, int x){
    p+=1<<X; maxseg[p]=x; p>>=1;
    while(p) maxseg[p]=max(maxseg[p<<1], maxseg[p<<1|1]), p>>=1;
}

int Min(int s, int e){
    s+=1<<X; e+=1<<X; int ret=inf;
    while(s<=e){
        if(s&1) ret=min(ret, minseg[s]);
        if(~e&1) ret=min(ret, minseg[e]);
        ++s>>=1; --e>>=1;
    }
    return ret;
}

int Max(int s, int e){
    s+=1<<X; e+=1<<X; int ret=-inf;
    while(s<=e){
        if(s&1) ret=max(ret, maxseg[s]);
        if(~e&1) ret=max(ret, maxseg[e]);
        ++s>>=1; --e>>=1;
    }
    return ret;
}

void dfs(int p){
    while(1){
        if(isin(l[p], r[p], rc[l[p]-1])){
            l[p]=Min(l[p]-1, r[p]);
            minu(p, l[p]);
        }
        else if(isin(l[p], r[p], lc[r[p]+1])){
            dfs(r[p]+1);
            r[p]=Max(l[p], r[p]+1);
            maxu(p, r[p]);
        }
        else break;
    }
}

signed main(){
    fastio;

    int n; cin >> n;
    for(int i=1; i<n; i++){
        int a; cin >> a;
        rc[i]=lc[i+1]=a;
    }

    for(int i=1; i<=n; i++){
        l[i]=r[i]=i;
        minu(i, i); maxu(i, i);
        int b; cin >> b;
        for(int j=0; j<b; j++){
            int a; cin >> a;
            k[a].push_back(i);
        }
    }

    for(int p=1; p<=n; p++) dfs(p);
    
    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        if(l[a]<=b && b<=r[a]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
