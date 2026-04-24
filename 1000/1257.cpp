#include<bits/stdc++.h>
using namespace std;long long n,m,l,D[10101],V[10101],v[1010],i,d,p,t;int main(){cin>>m>>n;for(;i<n;)cin>>v[i],l=max(l,v[i++]);fill(D+1,D+l,-l);priority_queue<array<int,2>>Q;Q.push({0,0});while(Q.size()){t=Q.top()[1];Q.pop();if(!V[t]++)for(i=0;i<n;){p=(t+v[i++])%l,d=t<p;if(D[p]<D[t]-d)D[p]=D[t]-d,Q.push({D[p],p});}}cout<<m/l-D[m%l];}
