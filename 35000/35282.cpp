#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

auto sol = [](int n, int q, auto qs) {
	vector v(n + 1, i64(1));
	vector c(n / 400 + 1, i64(0));
	auto f = [&](int i) {
		return v[i] + c[i / 400];
	};
	auto update = [&](int i, int x) {
		while (i % 400 != 0 && i<= n) v[i] += x, i++;
		while (i <= n) c[i / 400] += x, i += 400;
	};
	auto query = [&](int a, int b) {
		while (a != b) {
			if (a < b) swap(a, b);
			i64 x = f(a);
			if (x > 100) {
				a = max(a - x, i64(1));
				continue;
			}
			int lo = 0, hi = a;
			while (lo + 1 < hi) {
				int mid = lo + hi >> 1;
				if (f(mid) != x) lo = mid;
				else hi = mid;
			}
			if (x != f(b)) {
				i64 v1 = (a - hi) / x + 1;
				a = max(a - x * v1, i64(1));
			}
			else {
				if ((a - b) % x == 0) return b;
				i64 v1 = (a - hi) / x + 1;
				i64 v2 = (b - hi) / x + 1;
				a = max(a - x * v1, i64(1));
				b = max(b - x * v2, i64(1));
			}
		}
		return a;
	};
	vector ret(0, 0);
	for (int i = 0; i < q; i++) {
		auto [op, a, b] = qs[i];
		if (op == 1) update(a, b);
		else ret.push_back(query(a, b));
	}
	return ret;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q; cin >> n >> q;
	vector qs(q, array{ 0, 0, 0 });
	for (int i = 0; i < q; i++) cin >> qs[i][0] >> qs[i][1] >> qs[i][2];
	auto res = sol(n, q, qs);
	for (int x : res) cout << x << '\n';
}
