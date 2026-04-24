#include "towers.h"
#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

const int X=17;
struct persistent_segment_tree_sum{
    vector<array<int, 2>> seg[1<<X+1];
    void init(){
        for(int i=0; i<1<<X+1; i++) seg[i].push_back({0, 0});
    }

    void update(int p, int x, int t){
        p+=1<<X;
        while(p) seg[p].push_back({t, seg[p].back()[1]+x}), p>>=1;
    }

    int val(int p, int t){
        int x=upper_bound(seg[p].begin(), seg[p].end(), array<int, 2>{t, inf})-seg[p].begin()-1;
        return seg[p][x][1];
    }

    int sum(int s, int e, int t){
        s+=1<<X; e+=1<<X; int ret=0;
        while(s<=e){
            if(s&1) ret+=val(s, t);
            if(~e&1) ret+=val(e, t);
            ++s>>=1; --e>>=1;
        }
        return ret;
    }

    int walk(int v, int t, int p){
        if(p>=(1<<X)) return p-(1<<X);
        int vl=val(p<<1, t);
        if(vl>=v) return walk(v, t, p<<1);
        else return walk(v-vl, t, p<<1|1);
    }
} pst;

struct minmaxtree{
    array<array<int, 2>, 2> seg[1<<X+1];
    void update(int p, int x){
        seg[p+(1<<X)][0]=seg[p+(1<<X)][1]={x, p};
        p=p+(1<<X)>>1;
        while(p){
            seg[p][0]=min(seg[p<<1][0], seg[p<<1|1][0]);
            seg[p][1]=max(seg[p<<1][1], seg[p<<1|1][1]);
            p>>=1;
        }
    }

    array<int, 2> Min(int s, int e){
        array<int, 2> ret={inf, inf};
        s+=1<<X; e+=1<<X;
        while(s<=e){
            if(s&1) ret=min(ret, seg[s][0]);
            if(~e&1) ret=min(ret, seg[e][0]);
            ++s>>=1; --e>>=1;
        }
        return ret;
    }
    array<int, 2> Max(int s, int e){
        array<int, 2> ret={0, 0};
        s+=1<<X; e+=1<<X;
        while(s<=e){
            if(s&1) ret=max(ret, seg[s][1]);
            if(~e&1) ret=max(ret, seg[e][1]);
            ++s>>=1; --e>>=1;
        }
        return ret;
    }
} mmt;

int n, m;
vector<int> h, u;
vector<array<int, 3>> v;

void init(int N, vector<int> H){
    pst.init();

    n=N; h=H;
    for(int i=0; i<n; i++) mmt.update(i, h[i]);

    u.resize(n);
    for(int i=0; i<n; i++){
        if(i==0 || i==n-1 || (h[i-1]<h[i])^(h[i]<h[i+1])){
            if((i!=0 && h[i]>h[i-1]) || (i!=n-1 && h[i]>h[i+1])) v.push_back({h[i], i, 0});
            else{v.push_back({h[i], i, 1}); u[i]=1;}
        }
    }
    m=v.size();

    priority_queue<array<int, 3>> pq;
    set<int> st; st.insert(-1); st.insert(n);
    for(int i=0; i<m-1; i++) pq.push({-abs(v[i][0]-v[i+1][0]), v[i][1], v[i+1][1]});
    for(int i=0; i<m; i++){st.insert(v[i][1]); pst.update(v[i][1], v[i][2], 1);}

    while(pq.size()){
        int ds=-pq.top()[0], l=pq.top()[1], r=pq.top()[2]; pq.pop();
        if(st.find(l)==st.end() || st.find(r)==st.end()) continue;

        if(u[l]==1) pst.update(l, -1, ds+1);
        if(u[r]==1) pst.update(r, -1, ds+1);
        int L=*prev(st.find(l)), R=*next(st.find(r));
        st.erase(st.find(l)); st.erase(st.find(r));
        if(L!=-1 && R!=n){
            pq.push({-abs(h[L]-h[R]), L, R});
        }
    }
}

int max_towers(int l, int r, int d){
    int L=min(pst.walk(pst.sum(0, l-1, d)+1, d, 1), r);
    int R=max(pst.walk(pst.sum(0, r, d), d, 1), l);
    int ret=pst.sum(L, R, d);

    if(ret==0){
        int mx=mmt.Max(l, r)[1];
        int lmn=mmt.Min(l, mx)[1];
        int rmn=mmt.Min(mx, r)[1];
        return 1+(h[mx]-h[lmn]>=d && h[mx]-h[rmn]>=d);
    }

    if(L-l>=2){
        int lmx=mmt.Max(l, L-1)[1];
        int lmn=mmt.Min(l, lmx)[1];
        if(max(h[L], h[lmn])<=h[lmx]-d) ret++;
    }
    if(r-R>=2){
        int rmx=mmt.Max(R+1, r)[1];
        int rmn=mmt.Min(rmx, r)[1];
        if(max(h[R], h[rmn])<=h[rmx]-d) ret++;
    }

    return ret;
}
