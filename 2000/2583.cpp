#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int jaewon[100][100];
vector<int> hyungryun;
int m, n, k;

int dfs(int x, int y){
	if(jaewon[x][y] || x<0 || x>=m || y<0 || y>=n) return 0;
	jaewon[x][y]=1;
	return dfs(x, y+1)+dfs(x+1, y)+dfs(x, y-1)+dfs(x-1, y)+1;
}

int main() {
	cin >> m >> n >> k;
	for(int i=0; i<k; i++){
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j=x1; j<x2; j++){
			for(int l=y1; l<y2; l++) jaewon[l][j]=1;
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(!jaewon[i][j]) {
				int s=dfs(i, j);
				hyungryun.push_back(s);
			}
		}
	}
	sort(hyungryun.begin(), hyungryun.end());
	cout << hyungryun.size() << "\n";
	for(int i=0; i<hyungryun.size(); i++) cout << hyungryun[i] << " ";
}
