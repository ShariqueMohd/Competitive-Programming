#include<iostream>

#define li long long  int
using namespace std;

int main(){
    li N,b,d,i,x,garbage=0,cnt=0;
    cin>>N>>b>>d;
    for(i=0;i<N;i++){
        cin>>x;
        if(x>b)
            continue;
        garbage += x;
        if(garbage>d ){
            cnt+=1;
            garbage=0;
        }
    }

    if(garbage>d)
        cnt+=1;
    cout<<cnt<<"\n";


    return 0;
}
