#include "advisor.h"
#include <bits/stdc++.h>
using namespace std;
const int MX=202020;
int P[MX], NX[MX], T[MX], S[MX];
vector<array<int, 2>> B[MX];
void ComputeAdvice(int *C, int N, int K, int M) {
    for (int i=N-1; i>=0; i--) P[i]=N;
    for (int i=N-1; i>=0; i--) {NX[i]=P[C[i]]; P[C[i]]=i;}
    set<array<int, 2>> st;
    for (int i=0; i<K; i++) st.insert({P[i], i}), T[i]=P[i], B[i].push_back({i, 1});

    for (int i=0; i<N; i++) {
        if (st.find({T[C[i]], C[i]})==st.end()) {
            B[(*prev(st.end()))[1]].push_back({i+K, 0}); B[C[i]].push_back({i+K, 1});
            st.erase(prev(st.end()));
            T[C[i]]=NX[i]; st.insert({T[C[i]], C[i]});
        }
        else {
            B[C[i]].push_back({i+K, 1});
            st.erase(st.find({T[C[i]], C[i]}));
            T[C[i]]=NX[i]; st.insert({T[C[i]], C[i]});
        }
    }

    for (int i=0; i<N; i++) {
        sort(B[i].begin(), B[i].end());
        int pv=N+K;
        for (array<int, 2> j : B[i]) {
            if (j[1]==0) pv=N+K;
            else S[pv]=1, pv=j[0];
        }
    }

    for (int i=0; i<N+K; i++) WriteAdvice(S[i]);
}

#include "assistant.h"
#include <bits/stdc++.h>
using namespace std;
int F[MX];
void Assist(unsigned char *A, int N, int K, int R) {
    for (int i=0; i<K; i++) F[i]=1;

    vector<int> pp;
    for (int i=0; i<K; i++) if (!A[i]) pp.push_back(i);
    for (int i=0; i<N; i++) {
        int g=GetRequest();
        if (F[g]==0) {
            int x=pp.back(); pp.pop_back();
            PutBack(x);
            F[x]=0; F[g]=1;
        }
        if (!A[i+K]) pp.push_back(g);
    }
}
