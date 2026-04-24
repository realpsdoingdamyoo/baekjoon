#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

string s[1001];

bool cmp(string a, string b){
	string ab=a+b;
	string ba=b+a;
	if(ab>ba) return true;
	return false;
}

bool big(string a, string b){
	if(a.length()>b.length()) return true;
	if(a.length()<b.length()) return false;
	if(a>b) return true;
	return false;
}

int main() {
	fastio;
	int n, c=0, k;
	string max="0";
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		cin >> s[i];
		if(s[i]=="0") c++;
		max=big(max, s[i])?max:s[i]; 
	}
	if(n==c){cout << 0; return 0;}
	
	sort(s, s+n, cmp);
	for(int i=0; i<n; i++){
		cout << s[i];
		if(s[i]==max && s[i+1]!=max){
			for(int p=0; p<k-n; p++) cout << s[i];
		}
	}
	return 0;
}
