#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {	
	int n; cin >> n; 
	vector <pair<int, int>> v; 
	priority_queue <int, vector<int>, greater<int>> q; 
	int p, d; 
	for (int i = 0; i < n; i++) {
		cin >> p >> d; 
		v.push_back({ d,p }); 
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		q.push(v[i].second);  
		if (q.size() > v[i].first) {
			q.pop(); 
		}
	}
	int sum = 0; 
	while (!q.empty()) {
		sum += q.top(); 
		q.pop(); 
	}
	cout << sum; 
}
