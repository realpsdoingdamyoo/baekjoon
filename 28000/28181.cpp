#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

int P, R;

int input() {
    unsigned long long x;
    cin >> x;
    return x;
}
void print(int x) {
    vector<long long> v;
    if (x==0) v={0};
    while (x) v.push_back(x%10), x/=10;
    while (v.size()) cout << v.back(), v.pop_back();
    return;


    cout << (unsigned long long)(x);
}

int mtp(int a, int b) {
    int v=(1LL<<32)-1;
    int r1=a*(b&v);
    int r2=a*(b>>32)%P;
    return ((r2<<32)+r1)%P;
}

int pw(int x, int y) {
    int r=1;
    while (y) {
        if (y&1) r=mtp(x, r);
        x=mtp(x, x); y>>=1;
    }
    return r;
}
int inv(int x){return pw((x%P+P)%P, P-2);}
int isq(int x){return pw((x%P+P)%P, (P+1)/4);}

signed main() {
    fastio;

    P=1; P<<=64; P+=51;
    R=13748290127530984652;

    int T=input(), N=input();
    if (T==1) {
        set<int> st;
        int S=0, Q=1;
        for (int i=1; i<=N; i++) {
            int X=input()^R;
            if (st.find(X)!=st.end()) st.erase(st.find(X));
            else st.insert(X);
        }
        for (int i : st) S=(S+i)%P, Q=mtp(Q, i);

        print(S^R); cout << " "; print(Q^R);
        return 0;
    }

    int S1=input()^R, Q1=input()^R;
    set<int> st;
    int S2=0, Q2=1;
    for (int i=1; i<=N; i++) {
        int X=input()^R;
        if (st.find(X)!=st.end()) st.erase(st.find(X));
        else st.insert(X);
    }
    for (int i : st) S2=(S2+i)%P, Q2=mtp(Q2, i);

    int S, Q, A, B;

    S=(S2-S1+P)%P, Q=mtp(Q2, inv(Q1));
    A=mtp(S-isq(mtp(S, S)-4*Q)+P, inv(2));
    B=mtp(S+isq(mtp(S, S)-4*Q), inv(2));
    if (st.find(A)!=st.end() && st.find(B)!=st.end()) {
        print(A^R); cout << " "; print(B^R);
        return 0;
    }
    S=(S1-S2+P)%P, Q=mtp(Q1, inv(Q2));
    A=mtp(mtp(Q1, S), inv(Q1-Q2+P));
    B=mtp(S, inv(Q-1));
    if (st.find(B)!=st.end()) {
        print(A^R); cout << " "; print(B^R);
        return 0;
    }
    S=(S1-S2+P)%P, Q=mtp(Q1, inv(Q2));
    A=mtp(S-isq(mtp(S, S)-4*Q)+P, inv(2));
    B=mtp(S+isq(mtp(S, S)-4*Q), inv(2));
    print(A^R); cout << " "; print(B^R);

    return 0;
}
