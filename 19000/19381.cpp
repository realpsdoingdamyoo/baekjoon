#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vi baby[100003];
priority_queue<ll> q[100003];
vi c, ans;
ll sum;

void cjh(ll i, ll p){
    c[i]+=p;
    for(ll j : baby[i]) cjh(j, p+1);
}

void summ(ll i, ll q){
    if(ans[i]>q) ans[i]=q;
    sum+=abs(c[i]-ans[i]);
    for(ll j : baby[i]) summ(j, ans[i]);
}

int main() {
    ll n, a, s=0; cin >> n;
	c.resize(n+1); ans.resize(n+1);
	cin >> c[1];
	for(int i=2; i<=n; i++){
        cin >> a >> c[i];
        baby[a].push_back(i);
	}
	cjh(1, 0);
	for(int i=n; i>=1; i--){
        for(int j : baby[i]){
            if(q[j].size()>q[i].size()) swap(q[j], q[i]);
        }
        for(int j : baby[i]){
            while(!q[j].empty()){
                q[i].push(q[j].top());
                q[j].pop();
            }
        }
        q[i].push(c[i]); q[i].push(c[i]);
        int k=q[i].top();
        q[i].pop();
        ans[i]=q[i].top();
        //cout << i << q[i].top() << s << "\n";
	}
	summ(1, ans[1]);
	//for(int i=1; i<=n; i++) cout << i << " " << ans[i] << "\n";
	cout << sum;

    return 0;
}
