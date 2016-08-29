#include<iostream>
#include<cstdio>
#include<algorithm>
 
#define lli long long int
using namespace std;
const int MAX=1e4+5;
 
lli A[MAX];
 
int main(){
    int T,N,i;
    lli sum,ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        sum=0;
        for(i=0;i<N;i++){
            scanf("%lld",&A[i]);
            sum+=A[i];
        }
        sort(A,A+N);
        ans=0;
        sum-=A[0];
        for(i=1;i<N;i++){
            ans+=(sum-(N-i)*A[i-1]);
            sum-=A[i];
        }
        printf("%lld\n",ans);
    }
 
 
    return 0;
}
