#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef array<int, 2> pii;
typedef array<int, 3> tii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);


int main() {
	fastio;
	ll n, h; cin >> n >> h;
	vector<ll> v(n);
	for (int i=0; i<n; i++) cin >> v[i];
	ll mn=0;
	priority_queue<ll> left;
	priority_queue<ll, vector<ll>, greater<>> right;
	left.push(v[0]), right.push(v[0]);
	for (int i=1; i<v.size(); i++) {
		ll optl=left.top()-i*h, optr=right.top()+i*h;
		if (v[i]<optl) {
			left.push(v[i]+i*h);
			left.push(v[i]+i*h);
			left.pop();
			right.push(optl-i*h);
			mn+=optl-v[i];
		}
		else if (v[i]>optr) {
			right.push(v[i]-i*h);
			right.push(v[i]-i*h);
			right.pop();
			left.push(optr+i*h);
			mn+=v[i]-optr;
		}
		else {
			left.push(v[i]+i*h);
			right.push(v[i]-i*h);
		}
	}
	cout << mn << endl;
}
