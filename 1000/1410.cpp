#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

constexpr int MOD = 1'000'003;
int n, k, res;
string s[15];

int Popcnt(int n) {
	int ret = 0;
	for (; n; n -= n & -n) ret++;
	return ret;
}

int Binomial(int n, int r) {
	static int cache[16][16]{};
	if (r == 0 || r == n) return 1;
	int& ret = cache[n][r];
	if (ret) return ret;
	ret = Binomial(n - 1, r - 1) + Binomial(n - 1, r);
	if (ret >= MOD) ret -= MOD;
	return ret;
}

int F(int state) {
	int ret = 1;
	for (int j = 0; j < s[0].size(); j++) {
		char c = 0;
		for (int i = 0; i < n; i++) {
			if (~state & 1 << i || s[i][j] == '?') continue;
			if (c && s[i][j] != c) return 0;
			c = s[i][j];
		}
		if (!c) ret = ret * 26 % MOD;
	}
	return ret;
}

int main() {
	fastio;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 1; i < 1 << n; i++) {
		int cnt = Popcnt(i);
		if (cnt < k) continue;
		if (cnt + k & 1) res -= 1LL * Binomial(cnt, k) * F(i) % MOD;
		else res += 1LL * Binomial(cnt, k) * F(i) % MOD;
		if (res < 0) res += MOD;
		if (res >= MOD) res -= MOD;
	}
	cout << res << '\n';
}
