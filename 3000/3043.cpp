#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


ll N;
vector<pair<int, char>> result;

bool cmp(const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b) {
    if (a.second.first < b.second.first)
        return true;
    else if (a.second.first == b.second.first)
        return a.second.second < b.second.second;
    else
        return false;
}

void upDown(vector<pair<int, pair<int, int>>> &v) {
    vector<int> up, down;
    for (int i = 1; i <= N; i++) {
        if (v[i - 1].second.first > i)
            up.push_back(i);
        if (v[i - 1].second.first < i)
            down.push_back(i);
    }

    for (int i = 0; i < up.size(); i++) {
        for (int y = up[i]; y < v[up[i] - 1].second.first; y++)
            result.push_back(make_pair(v[up[i] - 1].first, 'U'));
    }

    reverse(down.begin(), down.end());
    for (int i = 0; i < down.size(); i++) {
        for (int y = v[down[i] - 1].second.first; y < down[i]; y++)
            result.push_back(make_pair(v[down[i] - 1].first, 'D'));
    }
}

void leftRight(vector<pair<int, pair<int, int>>> &v) {
    vector<int> left, right;
    for (int i = 1; i <= N; i++) {
        if (v[i - 1].second.first > i)
            left.push_back(i);
        if (v[i - 1].second.first < i)
            right.push_back(i);
    }

    for (int i = 0; i < left.size(); i++) {
        for (int x = left[i]; x < v[left[i] - 1].second.first; x++)
            result.push_back(make_pair(v[left[i] - 1].first, 'L'));
    }

    reverse(right.begin(), right.end());
    for (int i = 0; i < right.size(); i++) {
        for (int x = v[right[i] - 1].second.first; x < right[i]; x++)
            result.push_back(make_pair(v[right[i] - 1].first, 'R'));
    }
}

int main(void) {
    fastio;

    cin >> N;
    vector<pair<int, pair<int, int>>> yFirst;
    vector<pair<int, pair<int, int>>> xFirst;

    for (int i = 1; i <= N; i++) {
        int y, x;
        cin >> y >> x;
        yFirst.push_back(make_pair(i, make_pair(y, x)));
        xFirst.push_back(make_pair(i, make_pair(x, y)));
    }

    sort(yFirst.begin(), yFirst.end(), cmp);
    upDown(yFirst);
    sort(xFirst.begin(), xFirst.end(), cmp);
    leftRight(xFirst);

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++)
        cout << result[i].first << " " << result[i].second << "\n";

    return 0;
}
