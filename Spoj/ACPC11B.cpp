#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

const int MAX=1005;
int A[MAX],B[MAX];

int main(){
    int t,N,M;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d",&A[i]);
        }
        scanf("%d",&M);
        for(int i=0;i<M;i++){
            scanf("%d",&B[i]);
        }

        int diff=1e9;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(A[i]>=B[j]){
                    if(A[i]-B[j]<diff)
                        diff=A[i]-B[j];
                }
                else{
                    if(B[j]-A[i]<diff)
                        diff=B[j]-A[i];
                }
            }
        }
        printf("%d\n",diff);
    }



    return 0;
}
