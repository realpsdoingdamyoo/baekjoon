#include <iostream>
int e=1,l;main(){for(std::string s;l<6e3;std::cin>>s)for(char i:s)e+=!(i-'j'),l++;std::cout<<(l/e>99?"Real life":"Dreaming");}
