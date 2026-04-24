#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

struct node{
    node *t[2];
};

void Delete(node* T){
    if (T == nullptr) return;
    Delete(T->t[0]);
    Delete(T->t[1]);
    delete T;
}

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

int MinXor(vector<int>& a, vector<int>& b){
    if(a.size()==0 || b.size()==0) return 0;
    node *trie=new node();
    for(int i : a) Insert(trie, i);
    int ret=inf;
    for(int i : b) ret=min(ret, i^Find(trie, i));
    Delete(trie);
    return ret;
}

int mst(vector<int>& v, int k){
    if(v.size()<=1) return 0;
    if(k==-1) return 0;
    vector<int> a, b;
    for(int i : v){
        if((i&(1<<k))==0) a.push_back(i);
        else b.push_back(i^(1<<k));
    }

    int ret=mst(a, k-1)+mst(b, k-1)+MinXor(a, b);
    if(a.size() && b.size()) ret+=1<<k;

    return ret;
}

signed main(){
    fastio;

    int n; cin >> n;
    vector<int> v(n);
    for(int& i : v) cin >> i;

    cout << mst(v, 29);

    return 0;
}
