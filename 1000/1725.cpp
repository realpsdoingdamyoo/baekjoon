#import<iostream>
int h[1<<19],m,e=2e5,i,g;main(){std::cin>>g;for(;i<g;)std::cin>>h[++i];for(i++;~i;h[++e]=i--)while(h[h[e]]>h[i])g=h[h[e]]*(h[--e]+~i),m>g?:m=g;std::cout<<m;}
