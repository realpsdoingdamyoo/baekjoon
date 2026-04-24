#include <stdio.h>
int min2=100;
int min3=150;

void mine2r(int a){
    if(a<min2) min2=a;
}
void mine3r(int a){
    if(a<min3) min3=a;
}

int main() {
    int num[7];
    int n, min1=51, max1=0;
    scanf("%d", &n);
    for(int i=1; i<7; i++){
        scanf("%d", &num[i]);
        if(min1>num[i]) min1=num[i];
        if(max1<num[i]) max1=num[i];
    }

    if(n==1){
        printf("%d", num[1]+num[2]+num[3]+num[4]+num[5]+num[6]-max1);
    }
    else{
    mine2r(num[1]+num[2]);
    mine2r(num[1]+num[3]);
    mine2r(num[1]+num[4]);
    mine2r(num[1]+num[5]);
    mine2r(num[2]+num[3]);
    mine2r(num[2]+num[4]);
    mine2r(num[2]+num[6]);
    mine2r(num[3]+num[5]);
    mine2r(num[3]+num[6]);
    mine2r(num[4]+num[5]);
    mine2r(num[4]+num[6]);
    mine2r(num[5]+num[6]);


    mine3r(num[1]+num[2]+num[3]);
    mine3r(num[1]+num[2]+num[4]);
    mine3r(num[1]+num[3]+num[5]);
    mine3r(num[1]+num[4]+num[5]);
    mine3r(num[6]+num[2]+num[3]);
    mine3r(num[6]+num[2]+num[4]);
    mine3r(num[6]+num[3]+num[5]);
    mine3r(num[6]+num[4]+num[5]);

    long long int sum1, sum2, sum3;
    sum1=4*(n-1)*min1+(n-2)*min1;
    sum1*=n-2;
    sum2=(4*(n-1)+4*(n-2))*min2;
    sum3=4*min3;
    printf("%lld", sum1+sum2+sum3);
    }
}
