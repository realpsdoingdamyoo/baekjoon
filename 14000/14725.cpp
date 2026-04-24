#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

struct trie{
    map<string, trie*> m;

    void insert(vector<string>& v, int idx){
        if(idx==v.size()) return;
        if(m.find(v[idx]) == m.end()){
            trie* tr=new trie;
            m.insert({v[idx], tr});
        }
        m[v[idx]]->insert(v, idx+1);
    }

    void dfs(int d){
        for(auto& i : m){
            forf(j, 0, d) cout << "--";
            cout << i.first << "\n";
            i.second->dfs(d+1);
            delete i.second;
        }
    }
};

int main()
{
	fastio;

    int n; cin >> n;
    trie* root=new trie;

    repeat(n){
        int num; cin >> num;
        vector<string> v(num);
        forf(j, 0, num) cin >> v[j];
        root->insert(v, 0);
    }
    root->dfs(0);
    delete root;

    return 0;
}
