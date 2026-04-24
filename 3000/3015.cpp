#include <bits/stdc++.h>    
using namespace std;    
typedef long long ll;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main() {
	fastio;
	ll n, nw, c=0; 
	stack<pair<ll, ll> > st;
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> nw;
		while(!st.empty() && st.top().first<=nw){
			if(st.top().first<nw){
				c+=st.top().second;
				st.pop();
			}
			else if(st.top().first==nw){
				c+=st.top().second;
				st.top().second++;
				break;
			}
		}
		if(st.empty() || st.top().first!=nw) st.push({nw, 1});
		c+=!(st.size()<2);
	}
	cout << c;
    return 0;
}
