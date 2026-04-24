#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define SZ(a) int(a.size())
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define F first
#define S second

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef double db;


struct SAT2
{
	int n;
	vector<VI> g[2];
	
	VI used;
	VI order;
	VI color;
	
	void init(int _n)
	{
		n = _n;
		g[0].resize(2 * n);
		g[1].resize(2 * n);
		used.resize(2 * n);
		color.resize(2 * n);
	}
	void addEdge(int a, int b)
	{
		FOR(i, 0, 2)
		{
			g[i][a].PB(b);
			swap(a, b);
		}
	}
	//2u = don't take edge
	void addOrClause(int u, int xu, int v, int xv)
	{
		//(2*u + xu) || (2*v + xv)
		FOR(i, 0, 2)
		{
			addEdge((2 * u + xu) ^ 1, 2 * v + xv);
			swap(u, v);
			swap(xu, xv);
		}
	}
	
	
	void dfs(int v, int t, int col)
	{
		color[v] = col;
		used[v] = 1;
		for(int to : g[t][v])
			if(!used[to])
				dfs(to, t, col);
		if(t == 0)
			order.PB(v);
	}
	
	
	bool check()
	{
		FOR(i, 0, 2 * n)
		{
			if(!used[i])
				dfs(i, 0, -1);
		}
		reverse(ALL(order));
		fill(ALL(used), 0);
		int col = 0;
		for(int v : order)
		{
			if(used[v])
				continue;
			dfs(v, 1, col);
			col++;
		}
		
		FOR(i, 0, n)
			if(color[2 * i] == color[2 * i + 1])
				return false;
		return true;
	}
};



void solve()
{
	int n, m;
	cin >> n >> m;
	vector<string> grid(n + 2);
	grid[0] = grid[n + 1] = string(m + 2, '.');
	FOR(i, 0, n)
	{
		cin >> grid[i + 1];
		grid[i + 1] = "." + grid[i + 1] + ".";
	}
	n += 2;
	m += 2;
	
	SAT2 S;
	S.init(n * (m - 1) + m * (n - 1));
	
	int cntB = 0, cntW = 0;
	
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
		{
			int a = i * (m - 1) + (j - 1);			
			
			int b = n * (m - 1) + j * (n - 1) + (i - 1);
			if(grid[i][j] == '.')
			{
				S.addOrClause(a, 0, a, 0);
				S.addOrClause(b, 0, b, 0);
				continue;
			}
			int c = a + 1;
			int d = b + 1;
			
			
			if(grid[i][j] == 'W')
			{
				cntW++;
				S.addOrClause(a, 0, b, 0);
				S.addOrClause(a, 0, c, 0);
				S.addOrClause(a, 0, d, 0);
				S.addOrClause(b, 0, c, 0);
				S.addOrClause(b, 0, d, 0);
				S.addOrClause(c, 0, d, 0);
			
			
				if(grid[i][j - 1] != 'B')
					S.addOrClause(a, 0, a, 0);
				if(grid[i - 1][j] != 'B')
					S.addOrClause(b, 0, b, 0);
			
			}
			else
			{
				cntB++;
				S.addOrClause(a, 1, c, 1);
				S.addOrClause(a, 0, c, 0);
				S.addOrClause(b, 1, d, 1);
				S.addOrClause(b, 0, d, 0);
			
			
				if(grid[i][j - 1] != 'W')
					S.addOrClause(a, 0, a, 0);
				if(grid[i - 1][j] != 'W')
					S.addOrClause(b, 0, b, 0);
			}
		}	
	}
	
	
	if(S.check() && 2 * cntB == cntW)
		cout << "YES\n";
	else
		cout << "NO\n";
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();

	
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////
