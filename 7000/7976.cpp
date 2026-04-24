#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
	int n, k; vector<int> p, s;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		int t; cin >> t;
		p.push_back(t%2);
	}
	int ch=0, ss=0, minsss=n;
	for(int i=0; i<k; i++){
		int yoodam=0;
		s.push_back(0);
		for(int j=i; j<n; j+=k) {s[i]+=p[j]; yoodam++;}
		int sss=yoodam-s[i]<s[i]?yoodam-s[i]+0*(ch++):s[i];
		ss+=sss;
		minsss=minsss<(yoodam-sss>sss?yoodam-2*sss:2*sss-yoodam)?minsss:(yoodam-sss>sss?yoodam-2*sss:2*sss-yoodam);
	}
	if(ch%2) ss+=minsss;
	cout << ss;
	
    return 0;
}
