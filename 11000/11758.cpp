#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int x[4], y[4];
	for(int i=1; i<=3; i++) cin >> x[i] >> y[i];
	x[2]-=x[1]; x[3]-=x[1]; y[2]-=y[1]; y[3]-=y[1];
	int s=x[2]*y[3]-y[2]*x[3];
	cout << (s>0)-(s<0);
    return 0;
}
