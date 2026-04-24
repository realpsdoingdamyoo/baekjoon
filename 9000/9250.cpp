#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=1e18;

struct node {
    map<char, node*> mp;
    node* fa;
    int en=0;

    void insert(string s) {
        node* p=this;
        for (int i=0; i<s.length(); i++) {
            if (p->mp.find(s[i])==p->mp.end()) p->mp[s[i]]=new node();
            p=p->mp[s[i]];

            if (i==s.length()-1) p-> en=1;
        }
    }

    void fail() {
        node* rt=this;
        queue<node*> q; q.push(rt);

        while (q.size()) {
            node* p=q.front(); q.pop();
            for (pair<char, node*> cr : p->mp) {
                char x=cr.first; node* c=cr.second;

                if (p==rt) c->fa=rt;
                else {
                    node* pr=p->fa;
                    while (pr!=rt && pr->mp.find(x)==pr->mp.end()) pr=pr->fa;
                    if (pr->mp.find(x)!=pr->mp.end()) pr=pr->mp[x];
                    c->fa=pr;
                }
                if (c->fa->en) c->en=1;
                q.push(c);
            }
        }
    }
}* root=new node();

signed main(){
    fastio;

    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        string s; cin >> s;
        root->insert(s);
    }
    root->fail();

    int Q; cin >> Q;
    for (int i=1; i<=Q; i++) {
        string s; cin >> s;

        node* p=root; int en=0;
        for (char x : s) {
            while (p!=root && p->mp.find(x)==p->mp.end()) p=p->fa;
            if (p->mp.find(x)!=p->mp.end()) p=p->mp[x];
            if (p->en) {en=1; break;}
        }
        cout << (en?"YES\n":"NO\n");
    }

    return 0;
}
