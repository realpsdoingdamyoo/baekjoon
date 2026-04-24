#import<bits/stdc++.h>
using namespace std;long n,m,i,d;main(){while(cin>>n,n){m=i=d=0;vector<int>a(++n),s(n,-1);for(;i<n;s[++d]=i++){if(i<n-1)cin>>a[i];for(;d&&a[s[d]]>a[i];)m=max(m,a[s[d--]]*(i-s[d]-1));}cout<<m<<" ";}}
