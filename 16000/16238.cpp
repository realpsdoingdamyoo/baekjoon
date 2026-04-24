#include <bits/stdc++.h>
using namespace std;int n,s[1005],r,i;int main(){cin>>n;for(;i<n;)cin>>s[i++];sort(s,s+n);for(;i;)r+=max(i-n+s[--i],0);cout<<r;}
