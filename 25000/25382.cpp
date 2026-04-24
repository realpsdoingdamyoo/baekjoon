#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n;
int y[252525], s[252525], e[252525], id[252525], ans[252525];
vector<array<int, 2>> r[252525];

const int X=18;
int mxseg[1<<X+1];
void mxupdate(int p, int x){
    p+=1<<X;
    while(p) mxseg[p]=max(mxseg[p], x), p>>=1;
}
int Max(int s, int e){
    s+=1<<X; e+=1<<X; int ret=-inf;
    while(s<=e){
        if(s&1) ret=max(ret, mxseg[s]); ++s>>=1;
        if(~e&1) ret=max(ret, mxseg[e]); --e>>=1;
    } return ret;
}

int mnseg[1<<X+1];
void mnupdate(int p, int x){
    p+=1<<X;
    while(p) mnseg[p]=min(mnseg[p], x), p>>=1;
}
int Min(int s, int e){
    s+=1<<X; e+=1<<X; int ret=inf;
    while(s<=e){
        if(s&1) ret=min(ret, mnseg[s]); ++s>>=1;
        if(~e&1) ret=min(ret, mnseg[e]); --e>>=1;
    } return ret;
}

signed main(){
    fastio;

    for(int i=1; i<1<<X+1; i++) mxseg[i]=-inf, mnseg[i]=inf;

    cin >> n;
    for(int i=1; i<=n; i++){
        int x; cin >> x; id[x]=i;
        cin >> y[x] >> s[x] >> e[x];
    }

    for(int i=1; i<=n; i++){
        s[i]=max(s[i], Max(0, y[i])+1);
        mxupdate(y[i], s[i]);
    }

    for(int i=n; i>=1; i--){
        e[i]=min(e[i], Min(y[i], n)-1);
        mnupdate(y[i], e[i]);
    }

    for(int i=1; i<=n; i++) r[s[i]].push_back({e[i], id[i]});

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    for(int i=1; i<=n; i++){
        for(array<int, 2> j : r[i]) pq.push(j);
        if(pq.size()==0 || pq.top()[0]<i){
            cout << "NO";
            return 0;
        }
        ans[pq.top()[1]]=i;
        pq.pop();
    }

    cout << "YES\n";
    for(int i=1; i<=n; i++) cout << ans[i] << " ";

    return 0;
}
