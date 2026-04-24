#include <stdio.h>

int a[48], m[48], fa[48], c=0;
int n;

int good(){
    for(int i=0; i<n; i++){
        if(a[i]!=i%3) return 0;
    }
    return 1;
}

int mix(){
    if(good()==1) return 1;
    int b[48];
    for(int i=0; i<n; i++) b[m[i]]=a[i];
    for(int i=0; i<n; i++) a[i]=b[i];
    c++;
    for(int i=0; i<n; i++){
        if(a[i]!=fa[i]) return 0;
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        fa[i]=a[i];
    }
    for(int i=0; i<n; i++) scanf("%d", &m[i]);
    for(int i=0;; i++){
        if(mix()==1) {printf("%d", c); return 0;}
        if(mix()==-1) {printf("-1"); return 0;}
    }

    return 0;
}
