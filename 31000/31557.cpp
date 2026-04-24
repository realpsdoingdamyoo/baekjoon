#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

vector<int> u;

void diva(int n){
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            u.push_back(i);
            u.push_back(n/i);
        }
    }
}

signed main(){
	fastio;

	int n; cin >> n;
	vector<int> v(n);
	for(int& i : v) cin >> i;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	if(v.size()<=3){
        cout << (v[0]/4)*(v[0]/4+1)/2 << "\n";
        return 0;
	}

	diva(v[1]-v[0]);
	diva(v[2]-v[0]);
	diva(v[3]-v[0]);
	diva(v[2]-v[1]);
	diva(v[3]-v[1]);
	diva(v[3]-v[2]);
	sort(u.begin(), u.end());
	u.erase(unique(u.begin(), u.end()), u.end());

	int ans=0;
	for(int i : u){
        if(i>v[0]/4) break;
        set<int> st;
        for(int j : v) st.insert(j%i);
        if(st.size()<=3) ans+=i;
	}
	cout << ans;


    return 0;
}
