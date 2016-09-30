#include <iostream>
#include <cstdio>

#define ull unsigned long long int
using namespace std;
 
ull gcd(ull a,ull b){
 ull tmp;
   while(b!=0){
    tmp=a%b;
    a=b;
    b=tmp;
   }
  return a;
}
 
int main() {
	ull n,k;
	ull nn,p,q,common;
	while(scanf("%lld%lld",&n,&k)) {
      if(n==-1&&k==-1)
              break;
      else if(k <= 2)
         cout <<0<<endl;
      else{
         nn=(k-1)/2;
         p=(nn*k)-(nn*(nn+1));

         q=((n-1)*n)/2;
         common=gcd(p,q);
         p/=common;
         q/=common;
         if(q==1)
             printf("%lld\n",p);
         else
             printf("%lld/%lld\n",p,q);
      }
	}
	return 0;
}
