#include<iostream>
#include<algorithm>

#define li long int
using namespace std;

const int MAX=3e5+5;

li BIT[MAX],N,Q;

void update(li ind,li val){
    for(;ind<=N;ind+=ind&-ind)
        BIT[ind]+=val;
}

int query(li x){
    li sum=0;
    for(;x>0; x-=x&-x){
        sum+=BIT[x];
    }
    return sum;
}

int main(){
    li x;
    li diff=0,y;
    cin>>N>>Q;
    for(int i=0;i<Q;i++){
        cin>>x>>y;
        if(x==1){
            update(y,1);
            cout<<query(N)-diff<<"\n";
        }
        else if(x==2){
            int tmp=query(y)-query(y-1);
            update(y,-tmp);
            cout<<query(N)-diff<<"\n";
        }
        else{
            diff+=y;
            cout<<query(N)-y<<"\n";
        }
    }
    
    return 0;
}
