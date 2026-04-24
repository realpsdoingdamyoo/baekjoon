#import<iostream>
int64_t n,a,i=1;main(){std::cin>>n;while(i++<n)a+=n/i*i-i;std::cout<<a%1000000;}
