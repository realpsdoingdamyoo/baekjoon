#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int maxn=1000001;
#define rep(i,a,b) for(int i = a; i < b; i++)
typedef pair<int, int> pii;
#define sf1(a) cin >> a
typedef queue<int> qi;
#define sf2(a,b) cin >> a >> b
#define pf1l(a) cout << (a) << '\n'
#define pb(x) push_back(x)
#define X first
#define Y second



int n;
vi occur[1010005];
pii shirt[1010005];

int choice[1010005];
int isused[1010005];

vector<pii> adj[1010005];
pii p[1010005];
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  sf1(n);
  qi fixed;
  rep(i,0,n){
    int a,b;
    sf2(a,b);
    if(a == b){
      if(isused[a]){
        pf1l(-1);
        return 0;
      }
      fixed.push(a);
      isused[a] = 1;
      choice[i] = a;
      shirt[i] = {a, a};
    }
    else{
      occur[a].pb(i);
      occur[b].pb(i);
      shirt[i] = {a,b};
    }
  }
  while(!fixed.empty()){
    int cur = fixed.front(); fixed.pop();
    for(auto v : occur[cur]){
      if(choice[v] != 0) continue;
      int other = shirt[v].X + shirt[v].Y - cur;
      if(isused[other]){
        pf1l(-1);
        return 0;
      }
      isused[other] = 1;
      choice[v] = other;
      fixed.push(other);
    }
  }
  rep(i,0,n){
    if(choice[i] != 0) continue;
    int a, b;
    tie(a,b) = shirt[i];
    adj[a].pb(make_pair(b, i));
    adj[b].pb(make_pair(a, i));
  }
  rep(i,1,1000001){
    if(isused[i]) continue;
    int left = -1;
    queue<int> q;
    q.push(i);
    isused[i] = 1;
    while(!q.empty()){
      int cur = q.front(); q.pop();
      for(auto nxt : adj[cur]){
        if(isused[nxt.X]){
          if(nxt.X == p[cur].X || left == nxt.Y) continue;
          else{
            if(left != -1){
              pf1l(-1);
              return 0;
            }
            left = nxt.Y;
            continue;
          }
        }
        p[nxt.X] = {cur, nxt.Y};
        choice[nxt.Y] = nxt.X;
        q.push(nxt.X);
        isused[nxt.X] = 1;
      }
    }
    if(left != -1){
      int a, b;
      tie(a, b) = shirt[left];
      choice[left] = a;
      while(a != i){
        choice[p[a].Y] = p[a].X;
        a = p[a].X;
      }
    }
  }
  rep(i,0,n){
    pf1l(choice[i]);
    assert(choice[i] == shirt[i].X or choice[i] == shirt[i].Y);
  }
}
