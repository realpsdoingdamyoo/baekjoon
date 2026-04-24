#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

string L, W;
bitset<100005> can_use[505];
int N, l;
int fail[10001], len[10001], cache[100001];

int solve(int idx) {
	if (idx==l) return 0;
	int& ret=cache[idx];
	if (ret != -1) return ret;
	ret=solve(idx + 1);
	for (int i=0; i<N; ++i) {
		if (can_use[i][idx]) ret=max(ret, len[i] + solve(idx + len[i]));
	}
	return ret;
}

int main() {
	fastio;
	memset(cache, -1, sizeof(cache));
	cin >> L >> N;
	l=L.size();

	for (int k=0; k<N; k++) {
		cin >> W;
		memset(fail, 0, sizeof(fail));

		int w=W.size();
		len[k]=w;

		for (int i=1, j=0; i<w; i++) {
			while (j&&W[i] != W[j]) j=fail[j-1];
			if (W[i]==W[j]) fail[i]=++j;
		}

		for (int i=0, j=0; i<l; ++i) {
			while (j && L[i] != W[j]) j=fail[j-1];
			if (L[i]==W[j]) {
				if (j==w-1) {
					can_use[k][i-j]=true;
					j=fail[j];
				}
				else j++;
			}
		}
	}
	cout << solve(0);
	return 0;
}
