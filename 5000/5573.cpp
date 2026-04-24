#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int pan[1002][1002];
int vst[1002][1002];

int main(){
    fastio;
    int h, w, n; cin >> h >> w >> n;
    for(int i=1; i<=h; i++) for(int j=1; j<=w; j++) cin >> pan[i][j];
    vst[1][1]=n-1;
    for(int i=1; i<=h; i++) for(int j=1; j<=w; j++){
        if(i+j>2) vst[i][j]=(vst[i][j-1]/2+vst[i][j-1]%2*pan[i][j-1])+vst[i-1][j]/2+vst[i-1][j]%2*(1-pan[i-1][j]);
    }
    //for(int i=1; i<=h; i++) {for(int j=1; j<=w; j++) cout << vst[i][j] << " "; cout << endl;}
    int i=1, j=1;
    while(i<=h && j<=w){
        if((pan[i][j]+vst[i][j])%2) j++;
        else i++;
    }
    cout << i << " " << j << endl;
    return 0;
}
