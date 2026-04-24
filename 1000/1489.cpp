#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool cmp(int a, int b){return a>b;}

int main(){
	int n, t, s=0; cin >> n;
	vi a, b;
	for(int i=0; i<n; i++){cin >> t; a.push_back(t);}
	for(int i=0; i<n; i++){cin >> t; b.push_back(t);}
	sort(a.begin(), a.end()); sort(b.begin(), b.end(), cmp);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[i]>b[j] && b[j]){s+=2; a[i]=0; b[j]=0; break;}
		}
	}
	for(int i=0; i<n; i++){
		if(a[i]){
			for(int j=0; j<n; j++){
				if(a[i]==b[j] && b[j]){s++; b[j]=0; break;}
			}
		}
	}
	cout << s;
    return 0;
}
