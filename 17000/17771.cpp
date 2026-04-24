#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=4e18;

int N, CC[3];
array<int, 3> V[101010];
vector<array<int, 3>> U, L, C;

int vis[101010];

int ccw(array<int, 3> a, array<int, 3> b, array<int, 3> c) {
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
}

int pw(int x) {
    int r=1;
    while (x--) r=r*2%mod;
    return r;
}

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1] >> V[i][2], CC[V[i][2]]++;
    sort(V+1, V+N+1);

    for (int i=1; i<=N; i++) {
        while (U.size()>=2 && ccw(U[U.size()-2], U.back(), V[i])<0) U.pop_back();
        while (L.size()>=2 && ccw(L[L.size()-2], L.back(), V[i])>0) L.pop_back();
        U.push_back(V[i]); L.push_back(V[i]);
    }

    U.pop_back(); C=U;
    reverse(L.begin(), L.end());
    for (array<int, 3> i : L) C.push_back(i);
    C.pop_back();

    int D[2]={1, 1}, lzc=CC[0], cnt=0, bc=0, M=C.size();
    for (array<int, 3> i : C) {
        lzc-=!i[2];
        if (i[2]!=0 && i[2]!=bc) cnt++, bc=i[2];
    }

    if (cnt>=4) {cout << 0; return 0;}
    if (cnt==0) {cout << ((M*(M-1)+2)%mod*pw(lzc)-!CC[1]-!CC[2]+mod)%mod; return 0;}

    for (int i=0; i<M; i++) {
        if (vis[i] || C[i][2]) continue;
        int l=i, r=i, cc=-1;
        while (C[l][2]==0) vis[l]=1, l=(l+M-1)%M, cc++;
        while (C[r][2]==0) vis[r]=1, r=(r+1)%M, cc++;

        if (C[l][2]==C[r][2]) D[0]+=(cc+1)*cc/2;
        else D[1]*=cc+1;
    }
    D[0]%=mod; D[1]%=mod;

    if (cnt==1) cout << (D[0]*pw(lzc)-!CC[1]-!CC[2]+mod)%mod;
    else cout << (D[1]*pw(lzc)-!CC[1]-!CC[2]+mod)%mod;

    return 0;
}
