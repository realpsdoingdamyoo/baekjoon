#include <stdio.h>

int main() {
    int n;
    int su[50];
    int a, b, cnt=0;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &su[i]);
        if(i!=0 && su[i-1]==su[i]) cnt++;
    }
    if(n==1) {printf("A"); return 0;}
    else if(n==2){
        if(su[0]==su[1]) printf("%d", su[0]);
        else printf("A");
        return 0;
    }

    if(cnt==n-1){printf("%d", su[0]); return 0;}
    else if(su[0]==su[1]) {printf("B"); return 0;}


    else{
        if((su[2]-su[1])%(su[1]-su[0])!=0) {
            printf("B");
            return 0;
        }

        a=(su[2]-su[1])/(su[1]-su[0]);
        b=su[1]-su[0]*a;

        for(int i=0; i<n-1; i++){
            if(su[i]*a+b!=su[i+1]){printf("B"); return 0;}
        }
        printf("%d", a*su[n-1]+b);
    }
}
