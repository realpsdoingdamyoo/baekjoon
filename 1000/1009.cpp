#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    for(int j=0; j<t; j++){
        int a, b, f=1;
        scanf("%d %d", &a, &b);
        for(int i=0; i<b; i++){
            f*=a;
            f=f%10;
        }
        printf("%d\n", f==0?10:f);
    }
}
