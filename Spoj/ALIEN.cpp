#include<iostream>
#include<cstdio>
 
using namespace std;
 
long long int arr[100005];
 
 
int main(){
    int t,a,i,j,station,maxstation;
    long long int b,sum,maxsum;
    scanf("%d",&t);
    while(t--){
     sum=0;
     station=0;
     maxsum=10000001;
     maxstation=-1;
     scanf("%d%lld",&a,&b);
     for(i=0;i<a;i++){
        scanf("%lld",&arr[i]);
     }
 
     i=0;j=0;
     while(j<a){
        if((sum+arr[j])<=b){
            sum+=arr[j];
            station+=1;
            if((maxstation<=station)&&(sum<=b)){
                if(station==maxstation){
                    if(maxsum>sum)
                        maxsum=sum;
                }else{
                    maxsum=sum;
                }
                maxstation=station;
            }
            j+=1;
        }
        else{
           sum-=arr[i];
           station-=1;
           i+=1;
        }
     }
 
     printf("%lld %d\n",maxsum,maxstation);
    }
 
    return 0;
}
