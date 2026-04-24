#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define ll long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const ll mod=1000000007;

int n,m,w,X=1000000000;
priority_queue<array<int,3>> pq,tr;
int g[101010];

int Find(int x){return g[x]<0?x:g[x]=Find(g[x]);}
void Union(int a,int b){
    a=Find(a);b=Find(b);
    if(a==b) return;
    if(-g[a]<-g[b]) swap(a,b);
    g[a]+=g[b];g[b]=a;
}

int inv(int p){
    int r=1,x=p%mod;
    ll e=mod-2;
    while(e){
        if(e&1) r=(r*x)%mod;
        x=(x*x)%mod;
        e>>=1;
    }
    return r;
}

signed main(){
    fastio;
    ll N,M;cin>>N>>M;
    n=N;m=M;
    for(int i=0;i<m;++i){
        ll a,b,c;cin>>a>>b>>c;
        pq.push({-c,a,b});
    }
    for(int i=1;i<=n;++i) g[i]=-1;
    while(!pq.empty()){
        auto t=pq.top();pq.pop();
        int c=-t[0],u=t[1],v=t[2];
        if(Find(u)!=Find(v)){
            Union(u,v);
            w=(w+c)%mod;
            tr.push({-c,u,v});
        }
    }
    for(int i=1;i<=n;++i) g[i]=-1;
    __int128 ans=0;
    ll i2=inv(2);
    while(!tr.empty()){
        auto t=tr.top();tr.pop();
        int c=-t[0],u=t[1],v=t[2];
        int cu=Find(u),cv=Find(v);
        ll su=(-g[cu])%mod, sv=(-g[cv])%mod;
        int t1=((int)(X-c+1)%mod+mod)%mod;
        t1=(t1*(w%mod))%mod;
        ll Wm=w%mod;
        int t2=(((int)((2*Wm)%mod-c-1)%mod+mod)%mod);
        t2=(t2*(c%mod))%mod;
        t2=(t2*(int)i2)%mod;
        int tt=(t1+t2)%mod;
        int wy=(su*sv)%mod;
        ans=(ans+(int)tt*wy%mod)%mod;
        Union(u,v);
    }
    ll pc=(((__int128)N%mod)*(((__int128)(N-1)%mod))%mod)*i2%mod;
    ll dn=((((int)(X+1)%mod))*pc)%mod;
    ans=(ans%mod)*inv(dn%mod)%mod;
    cout<<(ll)(ans%mod);
    return 0;
}
