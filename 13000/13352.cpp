#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

struct vec2 {
    ll x, y;
};
 
bool ccw(vec2 a, vec2 b, vec2 c) {
    ll s = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
 
    return s == 0;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    int n; cin >> n;
    vector<vec2> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y;
 
    if (n <= 4) {
        cout << "success";
        return 0;
    }
 
    function<int()> myrand = [&]() -> int {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(0, n-1);
 
        return dist(mt);
    };
 
    int k = 100;
    bitset<100001> visit;
    for (int i = 1; i <= k; i++) {
        visit.reset();
 
        vector<int> can;
        while (can.size() < 4) {
            int t = myrand();
            while (visit[t]) t = myrand();
 
            visit[t] = true;
            can.push_back(t);
        }
 
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (ccw(arr[can[0]], arr[can[1]], arr[j]) ||
                ccw(arr[can[2]], arr[can[3]], arr[j]))
                cnt++;
        }
 
        if (cnt == n) {
            cout << "success";
            return 0;
        }
    }
    
    cout << "failure";
    return 0;
}
