#include<iostream>
#include<cstdio>
 
using namespace std;
 
int main(){
    int t,n,m,max1,max2,tmp,i;
    scanf("%d",&t);
    while(t--){
        max1=max2=-1;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d",&tmp);
            if(max1<tmp){
                max1=tmp;
            }
        }
        for(i=0;i<m;i++){
            scanf("%d",&tmp);
            if(max2<tmp){
                max2=tmp;
            }
        }
 
        if(max1<max2)
            printf("MechaGodzilla\n");
        else
            printf("Godzilla\n");
    }
 
    return 0;
}
