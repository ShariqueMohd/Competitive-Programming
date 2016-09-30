#include<iostream>
#include<cstdio>
#include<algorithm>
 
using namespace std;
 
int a[10005];
 
int main(){
    int i,j,avg,rem,n,sum,cnt,diff;
    bool flag;
    while(1){
        scanf("%d",&n);
        if(n==-1)
            break;
        sum=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        rem=sum%n;
        if(rem){
            printf("-1\n");
            continue;
        }
        avg=sum/n;
        sort(a,a+n);
 
        i=0; j=n-1; cnt=0;
        flag=1;
        while(i<=j&&flag){
            diff=a[j]-a[i];
            if(!diff)
                flag=0;
            else{
                if(2*avg-a[i]<=a[j]){
                    cnt+=(avg-a[i]);
                    a[j]-=(avg-a[i]);
                    a[i]=avg;
                    i+=1;
                    if(a[j]==avg)
                        j-=1;
                }
                else{
                    a[i]+=(a[j]-avg);
                    cnt+=(a[j]-avg);
                    a[j]=avg;
                    j-=1;
                }
            }
        }
        printf("%d\n",cnt);
 
    }
    return 0;
}
