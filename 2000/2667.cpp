#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int jaewon[100][100];
vector<int> hyungryun;
int m, n;

int dfs(int x, int y){
	if(!jaewon[x][y] || x<0 || x>=m || y<0 || y>=m) return 0;
	jaewon[x][y]=0;
	return dfs(x, y+1)+dfs(x+1, y)+dfs(x, y-1)+dfs(x-1, y)+1;
}

int main() {
	cin >> m;
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			scanf(" %1d", &jaewon[i][j]);
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			if(jaewon[i][j]) {
				int s=dfs(i, j);
				hyungryun.push_back(s);
			}
		}
	}
	sort(hyungryun.begin(), hyungryun.end());
	cout << hyungryun.size() << "\n";
	for(int i=0; i<hyungryun.size(); i++) cout << hyungryun[i] << "\n";
}
