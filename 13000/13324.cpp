#include<bits/stdc++.h>
using namespace std;int i,n,k,A[1<<20];main(){priority_queue<int>Q;cin>>n;for(;i<n;)cin>>k,Q.push(k-=i),Q.push(k),Q.pop(),A[i++]=Q.top();for(i--;i--;)A[i]=min(A[i],A[i+1]);for(;++i<n;)cout<<A[i]+i<<"\n";}
