#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vector<int> up[501], down[501];
int vsd[501][501];

void dfsu(int fu, int k){
    if(vsd[fu][k]) return;
    if(k!=fu) up[fu].push_back(k);
    vsd[fu][k]=1;
    vi p=up[k];
    for(int i : p) dfsu(fu, i);
}
void dfsd(int fd, int k){
    //cout << fd << " " << k <<" " << down[k].size() << endl;
    if(vsd[fd][k]) return;
    if(k!=fd) down[fd].push_back(k);
    vsd[fd][k]=1;
    vi p=down[k];
    for(int i : p) dfsd(fd, i);
}

int main(){
    int n, m, s=0;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        down[a].push_back(b);
        up[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {dfsu(i, i); vsd[i][i]=0; dfsd(i, i);}
    for(int i=1; i<=n; i++){
        int alv=0;
        for(int j=1; j<=n; j++) alv+=vsd[i][j];
        s+=(alv==n);
    }
    cout << s;
    return 0;
}
