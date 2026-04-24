#include <stdio.h>

int gcd(int a, int b){
    if(a*b==0) return a+b;
    else if(a==b) return a;
    else return gcd(a%b, b%a);
}

int main() {
    int d, p, q, m=2100000000;
    scanf("%d %d %d", &d, &p, &q);
    int togive;
    int minmon=((d-1)/gcd(p, q)+1)*gcd(p, q);
    for(int i=0; i<=d/p;i++){
        togive=p*i+((d-p*i)/q+((d-p*i)%q!=0))*q;
        if(m>togive) m=togive;
        if(m== minmon) break;
    }
    togive=(d/p+1)*p;
    if(m>togive) m=togive;
    printf("%d", m);
}
