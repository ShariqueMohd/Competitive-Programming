#include<iostream>
#include<cstdio>
#include<algorithm>

#define li long long int
using namespace std;
const int MAX=1e5+5;
li X[MAX],prefix[MAX],suffix[MAX];

int main(){
    li N,A,i,ind=0,cnt=0,ans=(li)(1e10+5);
    cin>>N>>A;
    for(i=0;i<N;i++){
        cin>>X[i];
        if(A>X[i])
            cnt+=1;
    }
    if(N==2){
        cout<<min(abs(A-X[0]),abs(A-X[1]));
        return 0;
    }
    sort(X,X+N);

    for(i=0;i<cnt;i++){
        prefix[i]=A-X[i];
    }
    for(i=0;i<N-cnt;i++){
        suffix[i]=X[cnt+i]-A;
    }


    li pre = 2*prefix[0]+suffix[N-cnt-2];
    li suff = 2*suffix[N-cnt-1]+prefix[1];
    ans = min(pre,suff);
    
    
    pre = 2*prefix[1] + suffix[N-cnt-1];
    suff = 2*suffix[N-cnt-2] + prefix[0];
    ans = min(ans,min(pre,suff));

    cout<<ans<<"\n";

    return 0;
}
