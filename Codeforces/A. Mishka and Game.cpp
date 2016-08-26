#include<iostream>

using namespace std;

int main(){
    int N,i,M=0,C=0,x,y;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>x>>y;
        if(x>y){
            M+=1;
        }
        else if(y>x){
            C+=1;
        }
    }
    if(M>C){
        cout<<"Mishka";
    }
    else if(C>M){
        cout<<"Chris";
    }
    else{
    cout<<"Friendship is magic!^^";
    }



}
