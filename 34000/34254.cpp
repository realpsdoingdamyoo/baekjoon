#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
vector<array<int, 4>> ans;
int v[1010101];

void flip(int a, int b, int c, int d) {
    ans.push_back({a, b, c, d});
}

void type1(int l, int r, int sl, int sr) {
    int p2=l+r>>1;
    int p1=l+p2>>1, p3=p2+1+r>>1;
    flip(l, p2, p2+1, r); flip(p1+1, p3, sl, sr);
    flip(l, p2, p2+1, r); flip(p1+1, p3, sl, sr);
}

void type2(int sl, int l) {
    flip(sl, sl+2, l, l+2); flip(sl, sl+2, l+2, l+4);
    flip(sl, sl+2, l, l+2); flip(sl, sl+2, l+1, l+3);
}

void type3(int l, int r, int sl, int sr) {
    int p2=l+r>>1;
    int p1=l+p2>>1, p3=p2+r>>1;
    flip(l, p2-1, p2+1, r); flip(p1, p3, sl, sr);
    flip(l, p2-1, p2+1, r); flip(p1, p3, sl, sr);
}

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) v[i]=i;

    M=N/8;
    if (N%4>1) {cout << "-1\n"; return 0;}
    if (N%8==0) {
        flip(1, 4*M, 4*M+1, 8*M); type1(2*M+1, 6*M, 6*M+1, 8*M);
        flip(1, 4*M, 4*M+1, 8*M); type1(2*M+1, 6*M, 6*M+1, 8*M);
    }
    else if (N%8==4) {
        flip(1, 4*M+2, 4*M+3, 8*M+4);
        flip(4*M+1, 4*M+4, 4*M+5, 4*M+8);
        flip(1, 4*M+2, 4*M+3, 8*M+4);
        flip(1, 3, 8*M-1, 8*M+1);
        flip(1, 3, 8*M, 8*M+2);
        flip(8*M-1, 8*M, 8*M+1, 8*M+2);
        flip(3, 4*M+2, 4*M+3, 8*M+2); type1(2*M+3, 6*M+2, 6*M+3, 8*M+2);
        flip(3, 4*M+2, 4*M+3, 8*M+2); type1(2*M+3, 6*M+2, 6*M+3, 8*M+2);
    }
    else if (N%8==1) {
        flip(1, 4*M, 4*M+1, 8*M); type1(2*M+1, 6*M, 6*M+1, 8*M);
        flip(1, 4*M, 4*M+1, 8*M); type1(2*M+1, 6*M, 6*M+1, 8*M);
        flip(1, 2*M+1, 6*M+1, 8*M+1);
        flip(1, 2*M+1, 4*M+1, 6*M+1);
        flip(4*M+2, 6*M+1, 6*M+2, 8*M+1);
        flip(2*M+1, 4*M+1, 6*M+1, 8*M+1);
        flip(1, 2*M+1, 6*M+1, 8*M+1);
        flip(2, 2*M+1, 2*M+2, 4*M+1);
    }
    else if (N==13) {
        flip(2, 7, 8, 13);
        flip(1, 4, 6, 9);
        flip(4, 7, 8, 11);
        flip(1, 5, 6, 10);
        flip(4, 8, 9, 13);
        flip(1, 5, 6, 10);
        flip(3, 5, 10, 12);
        flip(2, 4, 5, 7);
        flip(5, 6, 11, 12);
        flip(1, 2, 12, 13);
        flip(2, 3, 12, 13);
    }
    else {
        flip(1, 4*M+2, 4*M+4, 8*M+5);
        flip(4*M+1, 4*M+5, 4*M+6, 4*M+10);
        flip(1, 4*M+2, 4*M+4, 8*M+5);
        type2(1, 8*M-1);

        flip(3, 4*M+2, 4*M+4, 8*M+3); type3(2*M+3, 6*M+3, 6*M+4, 8*M+4);
        flip(3, 4*M+2, 4*M+4, 8*M+3); type3(2*M+3, 6*M+3, 6*M+4, 8*M+4);
    }
    if(N<100) flip(1, 1, 2, 2);

    cout << ans.size() << "\n";
    for (array<int, 4> i : ans) {
        for (int j : i) cout << j << " ";
        cout << "\n";

    }

    return 0;
}
