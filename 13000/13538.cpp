#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

struct node {
    int L, R;
    vector<int> vec;
} trie[10101010];
int S=1;

int M, N, A[505050];

const int X=20;
void Push(int n, int x) {
    int p=1;
    for (int i=X; i>=1; i--) {
        trie[p].vec.push_back(n);
        int& c=(x&(1<<i-1))?trie[p].R:trie[p].L;
        if (c==0) c=++S; p=c;
    }
    trie[p].vec.push_back(n);
}

int Count(int p, int L, int R) {
    vector<int>& v=trie[p].vec;
    return upper_bound(v.begin(), v.end(), R)-lower_bound(v.begin(), v.end(), L);
}

int Find(int L, int R, int x) {
    int p=1, r=0;
    for (int i=X; i>=1; i--) {
        int c=(x&(1<<i-1))?trie[p].L:trie[p].R;
        vector<int>& vec=trie[c].vec;
        if (c==0 || Count(c, L, R)==0) c=trie[p].L+trie[p].R-c;
        r|=(c==trie[p].R)<<i-1;
        p=c;
    }
    return r;
}

void Delete(int x) {
    int p=1;
    for (int i=X; i>=1; i--) {
        trie[p].vec.pop_back();
        int& c=(x&(1<<i-1))?trie[p].R:trie[p].L;
        if (c==0) c=++S; p=c;
    }
    trie[p].vec.pop_back();
}

int Less(int L, int R, int x) {
    int p=1, r=0;
    for (int i=X; i>=1; i--) {
        if (x&(1<<i-1)) r+=Count(trie[p].L, L, R);
        int& c=(x&(1<<i-1))?trie[p].R:trie[p].L;
        if (c==0) c=++S; p=c;
    }
    return r+Count(p, L, R);
}

int Kth(int L, int R, int K) {
    int p=1, r=0; K--;
    for (int i=X; i>=1; i--) {
        int ls=Count(trie[p].L, L, R);
        if (ls<=K) K-=ls, p=trie[p].R, r|=1<<i-1;
        else p=trie[p].L;
    }
    return r;
}

signed main() {
    fastio;

    cin >> M;
    for (int i=1; i<=M; i++) {
        int a, l, r, x; cin >> a;
        if (a==1) {
            cin >> x;
            A[++N]=x; Push(N, x);
        }
        else if (a==2) {
            cin >> l >> r >> x;
            cout << Find(l, r, x) << "\n";
        }
        else if (a==3) {
            cin >> x;
            while (x--) Delete(A[N--]);
        }
        else if (a==4) {
            cin >> l >> r >> x;
            cout << Less(l, r, x) << "\n";
        }
        else {
            cin >> l >> r >> x;
            cout << Kth(l, r, x) << "\n";
        }
    }

    return 0;
}
