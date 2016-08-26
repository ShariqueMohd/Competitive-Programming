#include<iostream>
#define lli long long int

using namespace std;

lli A[100005],sum=0;
bool is[100005];

int main(){
    int N,K,x,i;
    lli ans=0,cp=0;
    cin>>N>>K;
    for(i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
    }
    for(i=0;i<N;i++){
        ans+=(A[i]*A[(i+1)%N]);
    }
    //cout<<"ans: "<<ans<<"\n";
    lli tmp;
    while(K--){
        cin>>x;
        x-=1;
        tmp=(sum-A[x])*A[x];
        //cout<<tmp<<"\tbefore\n";
        if(!is[(x+1)%N] )
            tmp-=(A[x]*A[(x+1)%N]);
        int ind=x-1;
        if(ind<0)
            ind=N-1;
        if(!is[ind])
            tmp-=(A[x]*A[ind]);
        //cout<<"after: "<<tmp<<endl;
        tmp-=(A[x]*cp);
        ans+=tmp;
        is[x]=1;
        cp+=A[x];
    }
    cout<<ans;


    return 0;
}
