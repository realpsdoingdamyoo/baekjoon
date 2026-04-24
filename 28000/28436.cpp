#import<bits/stdc++.h>
using namespace std;int main(){long long t,c,w;cin>>t;while (t--){string s;char x='.';c=w=0;cin>>s;reverse(s.begin(),s.end());for(char i:s)if(i=='.')w+=c;else if(x==i)c+=c/abs(c);else if(x=='.')c+=(i<'W')*2-1,x=i;else c=0,x='.';cout<<(w>=0?"BLACK\n":"WHITE\n");}}
