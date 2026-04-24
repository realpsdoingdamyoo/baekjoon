#include <bits/stdc++.h>
#include "library.h"
using namespace std;
typedef int ll;
typedef vector<ll> vi;
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define pb push_back
#define all(v) v.begin(), v.end()

void nin(vi& nout, ll d){
    nout.erase(lower_bound(all(nout), d));
}

void Solve(ll n){
    if(n==1){
        vi v; v.pb(1);
        Answer(v);
        return;
    }
    vi ans;
    vi que(n, 1);
    vi nout;
    forf(i, 0, n) nout.pb(i);

    forf(i, 0, n){
        que[i]=0;
        if(Query(que)==1){
            ans.pb(i); nin(nout, i);
            que[i]=1; break;
        }
        que[i]=1;
    }
    forf(i, 0, n-1){
        ll s=1, e=nout.size();
        while(s<=e){
            forf(j, 0, n) que[j]=0;
            ll m=(s+e)/2;
            forf(j, 0, m) que[nout[j]]=1;

            ll ne=Query(que);
            que[ans[i]]=1;
            ll ye=Query(que);
            forf(j, 0, m+1) que[nout[j]]=0;
            que[ans[i]]=0;
            if(ne==ye) e=m-1;
            else s=m+1;
        }
        ans.pb(nout[e]); nin(nout, nout[e]);

    }
    forf(i, 0, n) ans[i]++;
    Answer(ans);

}
