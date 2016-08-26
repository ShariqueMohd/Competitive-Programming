#include<iostream>

#define li long int
using namespace std;

const int MAX=1e5+5;
li A[MAX];

int main(){
    int N,i,j,len,maxlen;
    cin>>N;
    for(i=0;i<N;i++)
        cin>>A[i];
    i=0;j=0;
    len=1, maxlen=1;

    while(i<N && j<N){
        if(j+1<N && A[j+1]>A[j] ){
            j+=1;
            len+=1;
            maxlen=max(len,maxlen);
        }
        else if(j+1<N && A[j+1]<=A[j]){
            while(i!=j){
                i+=1;
                len-=1;
            }
            i+=1; j+=1;
        }

        if(j==N-1)
            break;
    }
    cout<<maxlen<<"\n";

    return 0;
}
