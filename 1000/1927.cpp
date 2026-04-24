#include <stdio.h>

const int inf=2e9, SZ=202020;
struct PQ {
    int v[SZ];
    int en=0;

    void init() {
        for (int i=0; i<SZ; i++) v[i]=-inf;
    }

    void swap(int a, int b) {
        int t=v[a]; v[a]=v[b]; v[b]=t;
    }
    void push(int x) {
        int p=++en; v[p]=x;
        while (p>1) {
            if (v[p]>v[p/2]) swap(p, p/2);
            p>>=1;
        }
    }
    int top() {
        if (en<1) return 0;
        return v[1];
    }
    void pop() {
        if (en<1) return;
        swap(1, en); v[en]=-inf; en--;
        int p=1;
        while (p<=en) {
            if (v[p*2]>v[p] && v[p*2]>v[p*2+1]) {
                swap(p, p*2), p=p*2;
            }
            else if (v[p*2+1]>v[p] && v[p*2]<=v[p*2+1]) {
                swap(p, p*2+1), p=p*2+1;
            }
            else break;
        }
    }
    int size() {
        return en;
    }
} pq;

signed main() {
    pq.init();
    int n; scanf("%d", &n);
    while (n--) {
        //char s[10];
        int a;
        //scanf("%s", s);
        scanf("%d", &a);
        if (a>0) {
            //scanf("%d", &a);
            pq.push(-a);
        }
        else {
            printf("%d\n", -pq.top());
            pq.pop();
        }
    }

    return 0;
}
