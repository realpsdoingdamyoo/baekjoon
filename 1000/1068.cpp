#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v[100];
int mother, c, ban;

void dfs(int np){
	if(np==ban) return;
	int cc=1;
	for(int i=0; i<v[np].size(); i++){
		if(v[np][i]!=ban) {dfs(v[np][i]); cc=0;}
	}
	c+=cc;
}

int main() {
	int n; cin >> n;
    for(int i=0; i<n; i++){
		int s; 
		cin >> s;
		if(s==-1) mother=i;
		else v[s].push_back(i);
	}
	cin >> ban;
    dfs(mother);
    cout << c;
    return 0;
}
