#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> lnk[202020];
int pv, in[202020], out[202020];
int dep[202020], par[202020], gen[202020];

const int X=19;
int seg[1<<X+1];
void update(int p, int x){
    p+=1<<X;
    while(p) seg[p]+=x, p>>=1;
}
int sum(int s, int e){
    s+=1<<X; e+=1<<X; int ret=0;
    while(s<=e){
        if(s&1) ret+=seg[s]; ++s>>=1;
        if(~e&1) ret+=seg[e]; --e>>=1;
    } return ret;
}

array<int, 2> tp[1<<X+1];
void tupdate(int s, int e, int x){
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) tp[s]=max(tp[s], {dep[x], x}); ++s>>=1;
        if(~e&1) tp[e]=max(tp[e], {dep[x], x}); --e>>=1;
    }
}
int top(int p){
    p+=1<<X; array<int, 2> ret={0, 0};
    while(p) ret=max(ret, tp[p]), p>>=1;
    return ret[1];
}

void dfs(int p, int pre){
    in[p]=++pv;
    for(int i : lnk[p]) if(i!=pre){
        dep[i]=dep[p]+1; par[i]=p;
        dfs(i, p);
    }
    out[p]=++pv;
}

void initialize(int N, vector<int> A, vector<int> B){
    n=N;
    for(int i=0; i<n-1; i++){
        lnk[A[i]].push_back(B[i]);
        lnk[B[i]].push_back(A[i]);
    }
    dfs(0, -1);
}

int ans=0;
int generate(int v, bool result){
    if(result){
        gen[v]=1;
        int r=top(in[v]);
        ans-=(-sum(out[r], out[r]))/2;
        update(in[v], 1); update(out[r], -1);
        ans+=(-sum(out[r], out[r]))/2;
        return ans;
    }

    gen[v]=-1;
    int r=top(in[v]);
    ans-=(-sum(out[r], out[r]))/2;
    for(int i : lnk[v]) if(i!=par[v] && gen[i]!=-1){
        tupdate(in[i], out[i], i);
        update(out[r], sum(in[i], out[i]-1));
        update(out[i], -sum(in[i], out[i]-1));
        ans+=(-sum(out[i], out[i]))/2;
    }
    if(gen[r]!=-1) ans+=(-sum(out[r], out[r]))/2;
    return ans;
}
