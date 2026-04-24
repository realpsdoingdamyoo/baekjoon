#include <bits/stdc++.h>
using namespace std;
int n,t,i;
main(){
string s,A;
cin>>n>>t>>s;t=1<<n-t;
for(;i<1<<n;i+=t)
A=max(A,s.substr(i,t));
cout<<A;
}
