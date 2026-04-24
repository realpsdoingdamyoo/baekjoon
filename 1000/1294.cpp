#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string gett[20];

bool cmp(string a, string b){
	string ab=a+b;
	string ba=b+a;
	if(ab<ba) return true;
	return false;
}

int main(){
	ll n, s=0, ss=0; cin >> n;
	for(int i=0; i<n; i++) {cin >> gett[i]; s+=gett[i].length();}
	for(int i=0; i<s; i++){
		sort(gett+ss, gett+n, cmp);
		cout << gett[ss][0];
		gett[ss]=gett[ss].substr(1);
		if(gett[ss].length()==0) ss++;
	}
	return 0;
}
