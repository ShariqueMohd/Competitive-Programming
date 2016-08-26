#include<iostream>
#include<string.h>

using namespace std;

string S[55],A="",B="";
int main(){
    int N,M,i,j;
    cin>>N>>M;
    for(i=0;i<M;i++){
        A+="#";
        if(i>0)
            B+=".";
    }
    for(i=0;i<N;i++){
        if(i%2==0){
            cout<<A<<"\n";
        }
        else if(i%4==1){
            cout<<B<<"#"<<"\n";
        }
        else{
            cout<<"#"<<B<<"\n";
        }
    }


    return 0;
}
