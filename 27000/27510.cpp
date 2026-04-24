#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

const int N = 100010;
int n, a[N], b[N], id[N], f[N];
bool cmp(int x, int y) {return b[x] > b[y]; } 
void Max(int &x, int y) {if (x < y) x = y; }
void Min(int &x, int y) {if (x > y) x = y; }

struct edge{
	int to, nxt, w;
}e[N << 1];
int head[N], cnt;
void add(int u, int v, int w) {
	e[++cnt] = (edge) {v, head[u], w}, head[u] = cnt;
}

int rt, sum, son[N], siz[N];
int lnk[N], dep[N], dis[N][20];
bool vis[N];
void get_rt(int x, int fa, int Dep = 0) {
	siz[x] = 1, son[x] = 0;
	for (int i=head[x]; i; i=e[i].nxt) {
		int y = e[i].to;
		if (vis[y] || y == fa) continue;
		if (Dep) dis[y][Dep] = dis[x][Dep] + e[i].w;
		get_rt(y, x, Dep);
		siz[x] += siz[y], Max(son[x], siz[y]);
	}
	Max(son[x], sum - siz[x]);
	if (son[rt] > son[x]) rt = x;
}
void build(int x) {
	vis[x] = true;
	for (int i=head[x]; i; i=e[i].nxt) {
		int y = e[i].to;
		if (vis[y]) continue;
		rt = 0, sum = siz[y];
		get_rt(y, x), dep[rt] = dep[x] + 1, get_rt(rt, 0, dep[rt]);
		lnk[rt] = x, build(rt);
	}
}

#define pii pair<int, int>
#define fir first
#define sec second
#define mk make_pair
struct node{
	vector<pii> s;
	node() {s.clear(); }
	bool cmpl(pii a, pii b, pii c) {
		assert(a.fir < b.fir && b.fir < c.fir);
		return (__int128)(b.sec - a.sec) * (c.fir - b.fir) >= (__int128)(c.sec - b.sec) * (b.fir - a.fir);
	}
	void add(pii k) {
		if (s.size() && s[s.size() - 1].fir == k.fir)
			Min(k.sec, s[s.size() - 1].sec), s.pop_back();
		while (s.size() > 1 && cmpl(s[s.size() - 2], s[s.size() - 1], k)) s.pop_back();
		s.push_back(k);
	}
	int calc(int i, int k) {return s[i].sec - s[i].fir * k; }
	int query(int k) {
		int l = 0, r = s.size() - 1;
		while (l + 5 <= r) {
			int mid = (l + r) >> 1;
			if (calc(mid, k) < calc(mid + 1, k)) r = mid + 1;
			else l = mid;
		}
		int ret = inf;
		for (int i=l; i<=r; ++i) Min(ret, calc(i, k));
		return ret;
	}
}t[N];

void solve() {
	for (int i=1; i<=n; ++i) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	memset(f, 0x3f, sizeof(f));
	f[1] = 0;
	for (int i=1; i<=n; ++i) {
		int x = id[i];
		int p = x, Dep = dep[x]; 
		while (p) {
			Min(f[x], t[p].query(dis[x][Dep]));
			p = lnk[p], --Dep;
		}
		if (f[x] >= inf) continue;
		p = x, Dep = dep[x];
		while (p) {
			t[p].add(mk(-b[x], f[x] + a[x] + b[x] * dis[x][Dep]));
			p = lnk[p], --Dep;
		}
	}
	for (int i=1; i<=n; ++i) {
		int x = id[i];
		int p = x, Dep = dep[x];
		while (p) {
			Min(f[x], t[p].query(dis[x][Dep]));
			p = lnk[p], --Dep;
		}
	}
}
// f[y] + a[y] + b[y] * dis[y] = -b[y] * dis[x] + f[x]

vector<int> travel(vector<int> A, vector<signed> B, vector<signed> U, vector<signed> V, vector<signed> W) {
	n = A.size();
	for (int i=0; i<n-1; ++i)
		add(U[i] + 1, V[i] + 1, W[i]), add(V[i] + 1, U[i] + 1, W[i]);
	for (int i=1; i<=n; ++i)
		a[i] = A[i - 1], b[i] = B[i - 1];
	rt = 0, sum = son[0] = n;
	get_rt(1, 0), dep[rt] = 1, get_rt(rt, 0, 1);
	build(rt);
//	printf("lnk: "); for (int i=1; i<=n; ++i) printf("%d ", lnk[i]); putchar(10);
//	for (int i=1; i<=4; ++i) {
//		printf("dis %d: ", i); for (int j=1; j<=n; ++j) printf("%d ", dis[j][i]); putchar(10);
//	}
	solve();
	vector<int> ans;
	for (int i=2; i<=n; ++i) ans.push_back(f[i]);
	return ans;
}
