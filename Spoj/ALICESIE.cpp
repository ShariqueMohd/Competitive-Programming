#include<iostream>
#include<cstdio>
 
using namespace std;
 
int main(){
    int n,t,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=(n+1)/2;
        printf("%d\n",ans);
    }
 
    return 0;
}
