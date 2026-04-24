#include <bits/stdc++.h>    
using namespace std;    
typedef long long ll;

ll a[1000001];

int main() {
	ll n, mx=0, cnt=0; cin >> n;
	stack<ll> st;
	for(int i=0; i<n; i++){cin >> a[i]; mx=max(mx, a[i]);}
	st.push(mx); a[n]=mx;
	for(int i=0; i<=n; i++){
		while(!st.empty() && st.top()<=a[i]){
			cnt+=a[i]-st.top(); st.pop();
		}
		if(!st.empty() && st.top()>a[i]) st.pop();
		st.push(a[i]);
	}
	cout << cnt;
    return 0;
}
