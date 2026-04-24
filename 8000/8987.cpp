#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

array<int, 2> P[303030], v[303030];
vector<int> tree[303030];
int par[303030];
int vol[303030];
int pss[303030];
int chk[303030];
int r=0;

const int X=18;
struct treeseg{
    array<int, 2> seg[1<<X+1]={};

    void update(int p, array<int, 2> x){
        x[1]=p;
        p+=1<<X; seg[p]=x; p>>=1;
        while(p){
            seg[p]=min(seg[p<<1], seg[p<<1|1]);
            p>>=1;
        }
    }

    array<int, 2> mnp(int s, int e){
        array<int, 2> ret={inf, inf};
        s+=1<<X; e+=1<<X;
        while(s<=e){
            if(s&1) ret=min(ret, seg[s]);
            if(~e&1) ret=min(ret, seg[e]);
            ++s>>=1; --e>>=1;
        }
        return ret;
    }

    void maketree(int m, int h, int s, int e){
        if(s>e) return;
        array<int, 2> p=mnp(s, e);
        tree[m].push_back(p[1]);
        vol[p[1]]=(p[0]-h)*(pss[e]-pss[s-1]);
        maketree(p[1], p[0], s, p[1]-1);
        maketree(p[1], p[0], p[1]+1, e);
        if(m) r=m;
    }
} seg;

void dfspress(int p){
    for(int i : tree[p]) dfspress(i);
    if(tree[p].size()==1){
        int b=tree[p][0];
        vol[p]+=vol[b];
        tree[p]=tree[b];
    }
}

void dfspar(int p){
    for(int i : tree[p]) dfspar(i), par[i]=p;
}

priority_queue<array<int, 2>> st, pq[303030];
void dfspq(int p){
    for(int i : tree[p]) dfspq(i);
    if(tree[p].size()==0) pq[p].push({0, p});
    for(int i : tree[p]){
        array<int, 2> j=pq[i].top();
        pq[p].push({j[0]+vol[i], j[1]});
    }
}

signed main(){
    fastio;

    int n, k; cin >> n;
    for(int i=1; i<=n; i++) cin >> P[i][0] >> P[i][1];
    cin >> k;

    for(int i=2, j=1; i<n; i+=2, j++) v[j]={P[i][1], P[i+1][0]-P[i][0]};
    n=n/2-1;

    for(int i=1; i<=n; i++){
        seg.update(i, {v[i][0], i});
        pss[i]=pss[i-1]+v[i][1];
    }

    seg.maketree(0, 0, 1, n);

    dfspress(r); dfspq(r); dfspar(r);

    array<int, 2> j=pq[r].top(); j[0]+=vol[r];
    st.push(j);

    int ret=0;
    while(k--){
        if(st.size()==0) continue;
        array<int, 2> ar=st.top(); st.pop();
        ret+=ar[0];
        int p=ar[1];

        while(!chk[p]){
            vol[p]=0; chk[p]=1;
            for(int i : tree[p]){
                if(chk[i]==1) continue;
                array<int, 2> j=pq[i].top(); j[0]+=vol[i];
                st.push(j);
            }
            p=par[p];
        }
    }
    cout << ret << "\n";

    return 0;
}
