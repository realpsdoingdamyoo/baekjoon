#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
ll n, k,i, cnt[1<<17];lf f[1<<17];
lf M(ll a, ll b){return (f[a]-f[b])/(a-b);}
bool alien(lf pen){deque<ll> q;q.push_back(0);
for(i=1;i<=n;i++){while(q.size()>=2 && M(q[0], q[1])>1e5/i) q.pop_front();
ll j=q.front();f[i]=f[j]+1e5*(i-j)/i-pen;
cnt[i]=cnt[j]+1;while(q.size()>=2 && M(q[q.size()-2], q[q.size()-1])<M(q[q.size()-1], i)) q.pop_back();
q.push_back(i);}return cnt[n]>=k;}
int main(){
cin>>n>>k;lf s=0,e=1e10,m;
while(e-s>=1e-9){m=(s+e)/2;if(alien(m))s=m;else e=m;}
printf("%.9lf",(f[n]+m*k)/1e5);}
