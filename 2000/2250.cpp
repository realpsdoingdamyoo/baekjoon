#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int,int> v[10001];
int n, x[10001], mo;
vector<int> hei[10001];
int nn[10001];

int dfs(int p, int nx, int h){
	hei[h].push_back(p);
	int width=1;
	if(v[p].first>0) width+=dfs(v[p].first, nx, h+1);
	x[p]=nx+width;
	if(v[p].second>0) width+=dfs(v[p].second, nx+width, h+1);
	return width;
}

int main() {
	cin >> n;
	for(int i=1; i<=n; i++){
		int l, r, p;
		cin >> p >> l >> r;
		v[p]={l, r};
		nn[l]=1; nn[r]=1;
	}
	for(int i=1; i<=n; i++) if(!nn[i]) mo=i;
	dfs(mo, 0, 1);
	int maxwid=0, mwi=0;
	for(int i=1; hei[i].size(); i++){
		int wid=x[hei[i][hei[i].size()-1]]-x[hei[i][0]]+1;
		if(maxwid<wid){maxwid=wid; mwi=i;}
	}
	cout << mwi << " " << maxwid;
    return 0;
}
