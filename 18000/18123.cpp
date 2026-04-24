#include <bits/stdc++.h>
using namespace std;

int n, N, C, C1, C2;
vector<int> lnk[101010];
int P[101010];
int DEP[101010];

vector<int> D[101010];
vector<int> H[101010];

int O[101010];

int SZ[101010];

void szm(int p, int pre) {
    SZ[p]=1;
    for (int i : lnk[p]) if (i!=pre)
        szm(i, p), SZ[p]+=SZ[i];
}

int getCent(int p) {
    for (int i : lnk[p]) if (SZ[i]<SZ[p] && SZ[i]>=(N+1)/2) return getCent(i);
    return p;
}

bool VIS[101010];
void dfs(int p) {
    VIS[p]=true;
    for (int i : lnk[p]) if (!VIS[i]) {
        DEP[i]=DEP[p]+1; P[i]=p; dfs(i);
    }
}

string ret;
void hashing(int p) {
    for (int i : H[p]) {
        ret+="1";
        hashing(i);
        ret+="0";
    }
}

int p_f(const std::pair<int, int>& p) { return p.first; }
int p_s(const std::pair<int, int>& p) { return p.second; }
template <typename T> int implicit_int(const T& v) { return v; }

template <typename T>
std::vector<T> counting_sort(const std::vector<T>& arr,
    int(*fun)(const T&) = implicit_int) {
    if(arr.empty()) return arr;

    int mx = 0;
    for(const T& i : arr) mx = std::max(mx, (int) fun(i));

    std::vector<std::vector<T>> res(mx + 1);
    for(const T& i : arr) res[fun(i)].push_back(i);
    std::vector<T> ans(arr.size());
    int idx = 0;
    for(const auto& i : res) for(const T& j : i) ans[idx++] = j;
    return ans;
}

/**
 * min(a[i]) >= 0
 * max(a[i][j]) <= sum(len(a[i]))
 * 위를 만족할 때 시복은 O(sum(len(a)))
 */
std::vector<int> sort_vectors(const std::vector<std::vector<int>>& a) {
    if(a.empty()) return {};

    int lm = 0, mx = 0;
    std::vector<std::pair<int, int>> ts;
    for(const auto& i : a) {
        lm = std::max(lm, (int) i.size());
        for(int j = 0; j < (int) i.size(); j++) {
            mx = std::max(mx, i[j]);
            ts.emplace_back(j, i[j]);
        }
    }
    ts = counting_sort(ts, p_s);
    ts = counting_sort(ts, p_f);

    std::vector<std::vector<int>> nonempty(lm);
    for(const auto& i : ts) {
        int idx = i.first, val = i.second;
        if(nonempty[idx].empty() || nonempty[idx].back() != val)
            nonempty[idx].push_back(val);
    }

    std::vector<std::vector<int>> length(lm + 1);
    for(int i = 0; i < (int) a.size(); i++)
        length[a[i].size()].push_back(i);

    std::vector<std::vector<int>> vec(mx + 1);

    std::vector<int> q;
    for(int l = lm; l >= 0; l--) {
        q.insert(q.begin(), length[l].begin(), length[l].end());
        if(!l) break;

        for(const auto& i : q)
            vec[a[i][l-1]].push_back(i);

        q.clear();
        for(const auto& i : nonempty[l-1]) {
            q.insert(q.end(), vec[i].begin(), vec[i].end());
            vec[i].clear();
        }
    }
    return q;
}

string gsh() {
    C=C1=C2=0;
    ret=""; N=n;
    for (int i=0; i<=N+3; i++) {
        lnk[i].clear(); D[i].clear(); H[i].clear();
        P[i]=DEP[i]=O[i]=SZ[i]=0; VIS[i]=false;
    }

    for (int i=1; i<N; i++) {
        int A, B; cin >> A >> B;
        A++; B++;
        lnk[A].push_back(B);
        lnk[B].push_back(A);
    }

    szm(1, 0); C=C1=C2=getCent(1);
    szm(C1, 0);
    for (int i : lnk[C1]) if (N%2==0 && SZ[i]==N/2) C2=i;

    if (C1!=C2) {
        for (int& i : lnk[C1]) if (i==C2) i=N+1;
        for (int& i : lnk[C2]) if (i==C1) i=N+1;
        lnk[N+1]={C1, C2}; C=++N;
    }

    dfs(C);
    for (int i=1; i<=N; i++) D[DEP[i]].push_back(i);

    for (int d=N; d>=0; d--) {
        vector<vector<int>> vec;
        for (int i : D[d]) {
            vector<int> pvc;
            for (int j : H[i]) pvc.push_back(O[j]);
            vec.push_back(pvc);
        }

        vector<int> s=sort_vectors(vec);

        int R=0;
        for (int i=0; i<D[d].size(); i++) {
            if (i>0 && vec[s[i]]==vec[s[i-1]]) R++;
            O[D[d][s[i]]]=i-R;
        }

        for (int i : s) H[P[D[d][i]]].push_back(D[d][i]);
    }

    hashing(C);
    if (n!=N) ret+="2";
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    unordered_set<long long> st;
    int T; cin >> T;
    while (T--) {
        cin >> n;
        string s=gsh();
        long long a=0;
        for (char i : s) a=a<<1|(i-'0');
        st.insert(a);
    }
    cout << st.size();

    return 0;
}
