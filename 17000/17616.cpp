#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vector<int> up[100005], down[100005];
int vsd[100005], iii, vui[100005], vdi[100005];

void dfsu(int k){
    if(vsd[k]) return;
    if(k!=iii) up[iii].push_back(k);
    vsd[k]=1;
    vi p=up[k];
    for(int ii : p) dfsu(ii);
}
void dfsd(int k){
    //cout << fd << " " << k <<" " << down[k].size() << endl;
    if(vsd[k]) return;
    if(k!=iii) down[iii].push_back(k);
    vsd[k]=1;
    vi p=down[k];
    for(int ii : p) dfsd(ii);
}

int main(){
    int n, m, s=0;
    cin >> n >> m >> iii;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        down[a].push_back(b);
        up[b].push_back(a);
    }
    dfsu(iii);
    int sm=0, la=n;
    for(int i=1; i<=n; i++){sm+=vsd[i]; vsd[i]=0;}
    vsd[iii]=0; dfsd(iii);
    for(int i=1; i<=n; i++){la-=vsd[i]; vsd[i]=0;}



    cout << sm << " " << la+1 << endl;
    return 0;
}
