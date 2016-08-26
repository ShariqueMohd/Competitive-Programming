#include<iostream>
#include<string.h>

using namespace std;

string H="hate ",L="love ",TI="that I ",IT="it";
int main(){
    int N,cnt=1,Tcnt=1;
    cin>>N;
    cout<<"I ";
    while(cnt<=N){
        if(cnt&1)
            cout<<H;
        else
            cout<<L;
        if(Tcnt<N){
            cout<<TI;
        }
        cnt+=1; Tcnt+=1;
    }
    cout<<IT<<"\n";


    return 0;
}
