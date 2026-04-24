#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int arr[1000][1000], n, m, cnt=0;
int dx[8]={ 0,1,1,1,0,-1,-1,-1 };
int dy[8]={ -1,-1,0,1,1,1,0,-1 };
vector<array<int, 2>> v1, v2;

bool bfs() {
    int len=v1.size();
    for (int i=0; i<len; i++) {
        int cx=v1[i][0], cy=v1[i][1];
        for (int j=0; j<8; j++) {
            int nx=cx+dx[j], ny=cy+dy[j];
            if (nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny]>0) {
                arr[nx][ny]-=1;
                if (arr[nx][ny]==0) v2.push_back({nx, ny});
            }
        }
    }
    if (v2.size()==0) return false;
    v1=v2; v2.resize(0);
    return true;
}

int main() {
	cin >> n >> m;
	char c;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++) {
			cin >> c;
			if (c=='.') {
				v1.push_back({i, j});
				arr[i][j]=0;
			}
			else arr[i][j]=c - '0';
		}
	}
	while(bfs()) cnt++;
	cout << cnt;
	return 0;
}
