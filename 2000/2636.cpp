#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int cheese[101][101], lc, llc, t;
int vsd[101][101];
vector<array<int, 2>> delc;
int n, m;

void cd(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m || vsd[x][y]) return;
    vsd[x][y]=1;
    if(cheese[x][y]) delc.push_back({x, y});
    else{cd(x+1, y); cd(x, y+1); cd(x-1, y); cd(x, y-1);}
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {cin >> cheese[i][j]; lc+=cheese[i][j];}
    }

    while(lc){
        llc=lc; t++; cd(0, 0);
        for(int i=0; i<delc.size(); i++) cheese[delc[i][0]][delc[i][1]]=0;
        lc-=delc.size(); delc.resize(0);
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) vsd[i][j]=0;
    }
    cout << t << endl << llc;
    return 0;
}
