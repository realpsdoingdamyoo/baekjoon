#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		int slen = s.length();
		int idx = slen;
		ll A = 0, k = 0, B = 0, l = 0;
		for (int i = 2; i < slen; i++) {
			if (s[i] == '(') {
				idx = i + 1;
				break;
			}
			A *= 10;
			A += s[i] - '0';
			k++;
		}
		for (; idx < slen; idx++) {
			if (s[idx] == ')') break;
			B *= 10;
			B += s[idx] - '0';
			l++;
		}
		ll k10 = 1, l10 = 1;
		while (k--) k10 *= 10;
		while (l--) l10 *= 10;

		ll ans1 = B + A * (l10 - 1), ans2 = k10 * (l10 - 1);
		if (ans2 == 0) ans1 = A, ans2 = k10;
		ll GCD = gcd(ans1, ans2);
		cout << ans1 / GCD << '/' << ans2 / GCD << '\n';
	}
}
