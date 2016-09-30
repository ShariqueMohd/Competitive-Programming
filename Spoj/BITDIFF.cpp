#include<iostream>
#include<cstdio>
#include<string.h>

#define lli long long int
using namespace std;
 
lli bit[32];
 
int main(){
    int i,num,t,base,j;
    lli ans,n,m=10000007;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%lld",&n);
        memset(bit,0,sizeof(bit));
        ans=0;
        for(i=0;i<n;i++){
            base=1;
            scanf("%d",&num);
            for(j=0;j<32;j++){
              if((num &(1<<j)))
                bit[j]+=1;
            }
        }
        for(i=0;i<32;i++){
            ans=(ans+(bit[i]*(n-bit[i])) )%m;
        }
        ans=(2*ans)%m;
        printf("Case %d: %lld\n",z,ans);
    }
 
    return 0;
}
