#include "simurgh.h"
#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int N, M;
vector<int> val, pre, f, inq;
vector<vector<array<int, 2>>> G;
vector<vector<int>> Q;
vector<int> UC, VC;

void DFS(int u, int fa) {
    inq[u]=1;
    for (array<int, 2> x : G[u]) {
        int v=x[0], w=x[1];
        if (pre[v]==-2) f[v]=u, pre[v]=w, DFS(v, u);
        else if (v!=fa && inq[v]) {
            vector<int> cyc;
            cyc.push_back(w);
            for (int i=u; i!=v; i=f[i]) cyc.push_back(pre[i]);
            Q.push_back(cyc);
        }
    }
    inq[u]=0;
}

int Find(int x, vector<int>& fd) {
    while (x!=fd[x]) x=fd[x]=fd[fd[x]];
    return x;
}

array<int, 2> qry(vector<int> E) {
    vector<int> fd(N);
    iota(fd.begin(), fd.end(), 0);

    int s=0;
    for (int i : E) fd[Find(UC[i], fd)]=Find(VC[i], fd);
    for (int i=1; i<N; i++) if (Find(f[i], fd)!=Find(i, fd))
        fd[Find(f[i], fd)]=Find(i, fd), E.push_back(pre[i]), s+=val[pre[i]];
    return {count_common_roads(E), s};
}

vector<int> find_roads(int n, vector<int> U, vector<int> V) {
    int m=U.size(); N=n; M=m; UC=U; VC=V;
    val=vector<int>(m, -1);
    pre=vector<int>(n, -2);
    f=vector<int>(n, -1);
    inq=vector<int>(n, 0);
    G.resize(n);
    for (int i=0; i<m; i++) {
        G[U[i]].push_back({V[i], i});
        G[V[i]].push_back({U[i], i});
    }

    pre[0]=-1; DFS(0, -1);

    for (auto& cyc : Q) {
        int cnt=0;
        for (int i : cyc) cnt+=val[i]<0;
        if (cnt<2) continue;
        if (cnt!=cyc.size()) {
            for (int i : cyc) if (~val[i]) {
                vector<int> cur;
                for (int j : cyc) if (j!=i) cur.push_back(j);
                int s=qry(cur)[0];
                for (int j : cyc) if (j!=cyc[0] && val[j]<0) {
                    cur.clear();
                    for (int k : cyc) if (j!=k) cur.push_back(k);
                    int t=qry(cur)[0];
                    val[j]=s-t+val[i];
                }
                break;
            }
        }
        else {
            vector<int> s;
            for (int i : cyc) {
                vector<int> cur;
                for (int j : cyc) if (j!=i) cur.push_back(j);
                s.push_back(val[i]=qry(cur)[0]);
            }
            int l=(*max_element(s.begin(), s.end()))-1;
            for (int i : cyc) val[i]=(val[i]==l);
        }
    }

    for (int i=1; i<n; i++) if (val[pre[i]]<0) val[pre[i]]=1;
    vector<int> ans;
    for (int i=0; i<m; i++) if (val[i]>0) ans.push_back(i);
    for (int i=0; i<n && ans.size()<n-1; i++) {
        vector<int> vec;
        for (array<int, 2> x : G[i]) if (val[x[1]]<0) vec.push_back(x[1]);
        while (vec.size()) {
            array<int, 2> x=qry(vec); int s=x[0], t=x[1];
            if (s==t) break;
            int z=0;
            for (int l=0, r=vec.size()-1; l<=r;) {
                int mid=l+r>>1;
                array<int, 2> y=qry(vector<int>(vec.begin(), vec.begin()+mid+1));
                if (y[0]==y[1]) l=mid+1;
                else z=mid, r=mid-1;
            }
            ans.push_back(vec[z]);
            for (int j=0; j<z; j++) val[vec[j]]=0;
            val[vec[z]]=1;
            vec.erase(vec.begin(), vec.begin()+z+1);
        }
        for (int j : vec) val[j]=0;
    }
    return ans;
}
