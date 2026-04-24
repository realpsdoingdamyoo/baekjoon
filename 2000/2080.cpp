#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int gcd(int a, int b){return b?gcd(b, a%b):a;}

signed main(){
	fastio;

    int n;
	cin >> n;
	map<array<int, 3>, vector<array<int, 2>>> mp;
	for(int i=0; i<n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1*MOD+y1>x2*MOD+y2) swap(x1, x2), swap(y1, y2);
        int a=y1-y2, b=x2-x1;
        int d=gcd(a, b); a/=d; b/=d;
        int c=a*x1+b*y1;
        mp[{a, b, c}].push_back({x1*MOD+y1, 1});
        mp[{a, b, c}].push_back({x2*MOD+y2, -1});
	}

	int ans=0;
	for(auto i : mp){
        vector<array<int, 2>> v=i.second;
        sort(v.begin(), v.end());
        int cnt=0;
        for(array<int, 2> j : v){
            if(j[1]==1) ans+=cnt;
            cnt+=j[1];
        }
	}
    cout << ans;

    return 0;
}
