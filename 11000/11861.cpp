#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef stack<ll> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
ll n;
ll h[1000002], maxx;
stack<ll> st;

int main() {
	cin >> n;
	for(int i=1; i<=n; i++) cin >> h[i];
	st.push(0);
	for(int i=1; i<=n+1; i++){
		while(!st.empty() && h[st.top()]>h[i]){
			ll hei=h[st.top()]; st.pop();
			ll wid=i-st.top()-1;
			
			ll ret=hei*wid;
			maxx=maxx>ret?maxx:ret;
		}
		st.push(i);
	}
	cout << maxx << endl;
    return 0;
}
