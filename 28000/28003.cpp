#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=200010, L=20, INF=1e18;
int n, q, a[N], l1[L][N], r1[L][N], l2[L][N], r2[L][N], d[N];

int query1(int l, int r) {
    int t=31-__builtin_clz(r-l+1);
    return max(l1[t][l], r1[t][r]);
}

int query2(int l, int r) {
    int t=31-__builtin_clz(r-l+1);
    return min(l2[t][l], r2[t][r]);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    a[0]=-INF, a[n+1]=INF;
    d[1]=d[n]=a[n]-a[1];
    for (int i=1; i<=n; i++) l1[0][i]=r1[0][i]=2*a[i]-a[i-1], l2[0][i]=r2[0][i]=2*a[i]-a[i+1];
    for (int i=1; i<L; i++) for (int j=1; j<=n; j++) {
        if (j+(1<<i)-1<=n) {
            l1[i][j]=max(l1[i-1][j], l1[i-1][j+(1<<(i-1))]);
            l2[i][j]=min(l2[i-1][j], l2[i-1][j+(1<<(i-1))]);
        }
        if (j-(1<<i)+1>=1) {
            r1[i][j]=max(r1[i-1][j], r1[i-1][j-(1<<(i-1))]);
            r2[i][j]=min(r2[i-1][j], r2[i-1][j-(1<<(i-1))]);
        }
    }
    for (int i=2; i<n; i++) {
        int l=i, r=i, t=0;
        if (a[i+1]-a[i]<a[i]-a[i-1]) r=i+1, t=1, d[i]=a[i+1]-a[i];
        else l=i-1, d[i]=a[i]-a[i-1];
        while (1<l || r<n) {
            if (t) {
                if (l==1) {
                    d[i]+=a[n]-a[r];
                    break;
                }
                int tmp=n;
                for (int s=r, e=n; s<=e; ) {
                    int m=(s+e)/2;
                    if (query2(r, m)<=a[l-1]) tmp=m, e=m-1;
                    else s=m+1;
                }
                d[i]+=a[tmp]-a[r]+a[tmp]-a[l-1], r=tmp, l--, t=0;
            }
            else {
                if (r==n) {
                    d[i]+=a[l]-a[1];
                    break;
                }
                int tmp=1;
                for (int s=1, e=l; s<=e; ) {
                    int m=(s+e)/2;
                    if (query1(m, l)>a[r+1]) tmp=m, s=m+1;
                    else e=m-1;
                }
                d[i]+=a[l]-a[tmp]+a[r+1]-a[tmp], l=tmp, r++, t=1;
            }
        }
    }
    cin>>q;
    while (q--) {
        int x; cin>>x;
        int p=lower_bound(a+1, a+n+1, x)-a;
        if (a[p]-x<x-a[p-1]) cout<<d[p]+a[p]-x<<"\n";
        else cout<<d[p-1]+x-a[p-1]<<"\n";
    }
    return 0;
}
