#include<iostream>
#include<algorithm>
#include<math.h>

#define lli long long int
using namespace std;

const int MAX=1e5+5;

lli C[MAX],T[MAX],A=1e9;

int main(){
    int N,M,i,j;
    lli dist=-1;
    cin>>N>>M;
    for(i=0;i<N;i++){
        cin>>C[i];
        C[i]+=A;
    }
    for(i=0;i<M;i++){
        cin>>T[i];
        T[i]+=A;
    }
    j=0;
    for(i=0;i<N;i++){
        while(j<M-1 && abs(T[j]-C[i]) >= abs(T[j+1]-C[i]))
            j+=1;
        dist=max(dist,abs(T[j]-C[i]));
    }
    cout<<dist<<"\n";

    return 0;
}

