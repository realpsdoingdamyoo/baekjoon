#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18, bnd=1e10;

int h, w;
vector<vector<int>> seat;
vector<array<int, 2>> loc;

const int X=20;
struct segtree{
    array<int, 3> seg[1<<X+1];
    array<int, 2> lazy[1<<X+1];

    array<int, 3> Merge(array<int, 3> a, array<int, 3> b){
        if(a>b) swap(a, b);
        if(a[0]==b[0] && a[1]==b[1]) a[2]+=b[2];
        return a;
    }

    void prop(int p){
        lazy[p<<1][0]+=lazy[p][0]; lazy[p<<1][1]+=lazy[p][1];
        lazy[p<<1|1][0]+=lazy[p][0]; lazy[p<<1|1][1]+=lazy[p][1];
        seg[p][0]+=lazy[p][0]; seg[p][1]+=lazy[p][1];
        lazy[p]={0, 0};
    }

    void segup(int p){
        array<int, 3> L=add(seg[p<<1], lazy[p<<1]);
        array<int, 3> R=add(seg[p<<1|1], lazy[p<<1|1]);
        seg[p]=Merge(L, R);
    }

    array<int, 3> add(array<int, 3> a, array<int, 2> b){
        a[0]+=b[0]; a[1]+=b[1]; return a;
    }

    void update(int s, int e, int x, int y){
        int ss=s+=1<<X, ee=e+=1<<X;
        for(int i=X; i>=1; i--) prop(ss>>i), prop(ee>>i);

        while(s<=e){
            if(s&1) lazy[s][0]+=x, lazy[s][1]+=y;
            if(~e&1) lazy[e][0]+=x, lazy[e][1]+=y;
            ++s>>=1; --e>>=1;
        }

        for(int i=1; i<=X; i++) segup(ss>>i), segup(ee>>i);
    }

    array<int, 3> query(int s, int e){
        s+=1<<X; e+=1<<X;
        for(int i=X; i>=1; i--) prop(s>>i), prop(e>>i);

        array<int, 3> ret={inf, inf, inf};
        while(s<=e){
            if(s&1) ret=Merge(ret, add(seg[s], lazy[s]));
            if(~e&1) ret=Merge(ret, add(seg[e], lazy[e]));
            ++s>>=1; --e>>=1;
        }

        return ret;
    }
} tree;

void give_initial_chart(int H, int W, vector<int> R, vector<int> C){
    h=H; w=W;
    seat=vector<vector<int>>(h+2, vector<int>(w+2, inf));
    for(int i=0; i<h*w; i++){
        loc.push_back({R[i]+1, C[i]+1});
        seat[R[i]+1][C[i]+1]=i;
    }

    for(int i=0; i<=h; i++) for(int j=0; j<=w; j++){
        vector<int> rec;
        for(int x : {0, 1}) for(int y : {0, 1}) rec.push_back(seat[i+x][j+y]);
        sort(rec.begin(), rec.end());
        if(rec[0]!=inf) tree.seg[rec[0]+(1<<X)][0]++;
        if(rec[1]!=inf) tree.seg[rec[1]+(1<<X)][0]--;
        if(rec[2]!=inf) tree.seg[rec[2]+(1<<X)][1]++;
        if(rec[3]!=inf) tree.seg[rec[3]+(1<<X)][1]--;
    }

    for(int i=1; i<h*w; i++) tree.seg[i+(1<<X)][0]+=tree.seg[i-1+(1<<X)][0];
    for(int i=1; i<h*w; i++) tree.seg[i+(1<<X)][1]+=tree.seg[i-1+(1<<X)][1];
    for(int i=0; i<h*w; i++) tree.seg[i+(1<<X)][2]=1;

    for(int i=(1<<X)-1; i>=0; i--) tree.seg[i]=tree.Merge(tree.seg[i<<1], tree.seg[i<<1|1]);
}

int swap_seats(int a, int b){
    for(int i=loc[a][0]-1; i<=loc[a][0]; i++) for(int j=loc[a][1]-1; j<=loc[a][1]; j++){
        vector<int> rec;
        for(int x : {0, 1}) for(int y : {0, 1}) rec.push_back(seat[i+x][j+y]);
        sort(rec.begin(), rec.end());
        if(rec[0]!=inf) tree.update(rec[0], h*w, -1, 0);
        if(rec[1]!=inf) tree.update(rec[1], h*w, 1, 0);
        if(rec[2]!=inf) tree.update(rec[2], h*w, 0, -1);
        if(rec[3]!=inf) tree.update(rec[3], h*w, 0, 1);
    }
    for(int i=loc[b][0]-1; i<=loc[b][0]; i++) for(int j=loc[b][1]-1; j<=loc[b][1]; j++){
        vector<int> rec;
        for(int x : {0, 1}) for(int y : {0, 1}) rec.push_back(seat[i+x][j+y]);
        sort(rec.begin(), rec.end());
        if(rec[0]!=inf) tree.update(rec[0], h*w, -1, 0);
        if(rec[1]!=inf) tree.update(rec[1], h*w, 1, 0);
        if(rec[2]!=inf) tree.update(rec[2], h*w, 0, -1);
        if(rec[3]!=inf) tree.update(rec[3], h*w, 0, 1);
    }

    swap(seat[loc[a][0]][loc[a][1]], seat[loc[b][0]][loc[b][1]]);
    swap(loc[a], loc[b]);

    for(int i=loc[a][0]-1; i<=loc[a][0]; i++) for(int j=loc[a][1]-1; j<=loc[a][1]; j++){
        vector<int> rec;
        for(int x : {0, 1}) for(int y : {0, 1}) rec.push_back(seat[i+x][j+y]);
        sort(rec.begin(), rec.end());
        if(rec[0]!=inf) tree.update(rec[0], h*w, 1, 0);
        if(rec[1]!=inf) tree.update(rec[1], h*w, -1, 0);
        if(rec[2]!=inf) tree.update(rec[2], h*w, 0, 1);
        if(rec[3]!=inf) tree.update(rec[3], h*w, 0, -1);
    }
    for(int i=loc[b][0]-1; i<=loc[b][0]; i++) for(int j=loc[b][1]-1; j<=loc[b][1]; j++){
        vector<int> rec;
        for(int x : {0, 1}) for(int y : {0, 1}) rec.push_back(seat[i+x][j+y]);
        sort(rec.begin(), rec.end());
        if(rec[0]!=inf) tree.update(rec[0], h*w, 1, 0);
        if(rec[1]!=inf) tree.update(rec[1], h*w, -1, 0);
        if(rec[2]!=inf) tree.update(rec[2], h*w, 0, 1);
        if(rec[3]!=inf) tree.update(rec[3], h*w, 0, -1);
    }

    array<int, 3> mn=tree.query(0, h*w-1);
    if(mn[0]==4 && mn[1]==0) return mn[2];
    else return 0;
}
