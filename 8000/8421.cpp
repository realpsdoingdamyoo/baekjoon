#import<iostream>
long long n,a,i;int main(){std::cin>>n;for(i=1;i<=n;i=n/(n/i)+1)a+=n/i*(n/(n/i)-i+1);std::cout<<a;}
