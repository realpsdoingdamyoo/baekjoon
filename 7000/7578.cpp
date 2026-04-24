#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll stree[2097153];

ll sum(ll s){
	ll i=20, ans=0,k=1;
	while(i>=0){
		if(s&(1<<i)){
			ans+=stree[k];
			k++;
		}
		k*=2;
		i--;
	}
	return ans;
}

void change(ll s, ll p){
	ll k=p-stree[1048576+s], q=2;
	for(ll i=0; i<=20; i++){
		q=(1<<i)+(s/(1<<(20-i)));
		stree[q]+=k;
	}
	return;
}


int main() {
    fastio;

    int n; cin >> n;
    vi v1(n), v2(n), used(1000003);
    forf(i, 0, n) {cin >> v1[i]; used[v1[i]]=i;}
    forf(i, 0, n) cin >> v2[i];

    forf(i, 0, n) v2[i]=used[v2[i]];

    forf(i, 0, n) stree[i+1048576]=0;

    for(ll i=19; i>=0; i--){
    	for(int j=(1<<i); j<(1<<(i+1)); j++){
    		stree[j]=stree[j*2]+stree[j*2+1];
		}
	}

    ll ans=0;
	for(int i=0; i<n; i++){
		change(v2[i], 1);
		ans+=sum(500005)-(v2[i]?sum(v2[i]+1):1);
	}
    cout << ans;
    return 0;
}
