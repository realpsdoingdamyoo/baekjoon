#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int> > v[100001];
int sel=0, maxdis=0;
int vsd[100001];

void dfs(int np, int dis){
	if(dis>maxdis){sel=np; maxdis=dis;}
	
	for(int i=0; i<v[np].size(); i++){
		if(!vsd[v[np][i].first]){
			vsd[v[np][i].first]=1;
			dfs(v[np][i].first, dis+v[np][i].second);
		}
	}
}

int main() {
	int n;
	cin >> n;
    for(int i=1; i<n; i++){
        int s, e, c;
        cin >> s >> e >> c;
        v[s].push_back({e,c});
        v[e].push_back({s,c});
    }
    vsd[1]=1;
    dfs(1, 0);
    for(int i=0; i<100001; i++) vsd[i]=0; maxdis=0; int ss=sel;
    vsd[ss]=1;
    dfs(ss, 0);
    cout << maxdis;
    return 0;
}
