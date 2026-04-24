#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

const int NOT_ADOPTER = 0;
const int EARLY_ADOPTER = 1;

int N;
vector<int> adj[MAX];
int visited[MAX];
int early_adopters;

void init() {
	cin >> N;
	int u, v;
	for(int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int dfs(int here) {
	visited[here] = true;

	int children[2] = {0, 0};
	for(int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if(!visited[next]) {
			children[dfs(next)]++;
		}
	}

	if(children[NOT_ADOPTER]) {
		early_adopters += 1;
		return EARLY_ADOPTER;
	}
	
	return NOT_ADOPTER;
}

void solve() {
	early_adopters = 0;
	dfs(1);
	cout << early_adopters;
}

int main() {
	init();
	solve();
	
	return 0;	
}
