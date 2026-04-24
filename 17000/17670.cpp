#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n, l;
int t[2020][2020], eat[2020], pss[2020][2020];
array<int, 2> cut[2020][2020];
int eatseq[2020];
array<int, 2> eatloc[2020];

void cutmake(int p){
    int s=0, c=0;
    for(int i=0; i<l; i++) s+=t[p][i];
    for(int i=0, j=0; i<n; i++){
        while(j<l && (c+t[p][j])*n<=s*(i+1)) c+=t[p][j], j++;
        array<int, 2> cw={j, 1};
        array<int, 2> tp={s*(i+1)-c*n, n*t[p][j]};
        cut[p][i]={cw[0]*tp[1]+tp[0]*cw[1], cw[1]*tp[1]};
    }
}

bool big(array<int, 2> a, array<int, 2> b){
    __int128 x=a[0], y=b[0]; x*=b[1]; y*=a[1];
    return x>y;
}

signed main(){
    fastio;

    cin >> n >> l;
    for(int i=0; i<n; i++) for(int j=0; j<l; j++) cin >> t[i][j];
    for(int i=0; i<n; i++) cutmake(i);

    for(int i=0; i<n; i++){
        int p=-1;
        for(int j=0; j<n; j++){
            if(eat[j]) continue;
            if(p==-1 || big(cut[p][i], cut[j][i])) p=j;
        }
        eatseq[i]=p;
        eat[p]=1;
        eatloc[i]=cut[p][i];
    }

    for(int i=0; i<n-1; i++) cout << eatloc[i][0] << " " << eatloc[i][1] << "\n";
    for(int i=0; i<n; i++) cout << eatseq[i]+1 << " ";

    return 0;
}
