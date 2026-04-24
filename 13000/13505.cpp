#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

struct node{
    node *t[2];
} trie;

void Insert(node* T, int p){
    for(int i=29; i>=0; i--){
        int b=!!(p&(1<<i));
        if(T->t[b]==nullptr) T->t[b]=new node();
        T=T->t[b];
    }
}

int Find(node* T, int p){
    int ret=0;
    for(int i=29; i>=0; i--){
        int b=!!(p&(1<<i));
        if(T->t[b]==nullptr) T=T->t[b^1], ret=ret*2+(b^1);
        else T=T->t[b], ret=ret*2+b;
    }
    return ret;
}


signed main(){
    fastio;

    int n; cin >> n;
    vector<int> v(n);
    for(int& i : v) cin >> i;

    for(int i : v) Insert(&trie, i);
    int x=(1<<30)-1, ans=0;
    for(int i : v) ans=max(ans, i^Find(&trie, x^i));
    cout << ans << "\n";

    return 0;
}
