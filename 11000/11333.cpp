#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll oooo[10005]={1,0,0,3,0,0,13,}, n, t;

int main() {
	for(int i=9; i<10005; i+=3) oooo[i]=(oooo[i-3]*5-oooo[i-6]*3+oooo[i-9]+1000000007*337301LL)%1000000007;
	
	cin >> t;
	while(t--){
		cin >> n;
		cout << oooo[n] << endl;
	}
	return 0;
}
