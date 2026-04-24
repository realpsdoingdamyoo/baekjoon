#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n, xyz[100], s[3], e[3], ss=0;
	cin >> s[0] >> s[1] >> s[2] >> e[0] >> e[1] >> e[2] >> n;
	for(int i=0; i<n; i++) cin >> xyz[i];
	sort(xyz, xyz+n);
	int d=(e[0]-s[0])*(e[0]-s[0])+(e[1]-s[1])*(e[1]-s[1])+(e[2]-s[2])*(e[2]-s[2]);
	for(int i=0; i<n-1; i++) ss+=xyz[i];
	if((xyz[n-1]+ss)>=sqrt(d) && (xyz[n-1]-ss)<=sqrt(d)) cout << "YES";
	else cout << "NO";
    return 0;
}
