#include<iostream>
#include<algorithm>

#define li long int
using namespace std;

const int MAX=1e5+5;
li A[MAX],ans[MAX];

int main(){
    int N,i,mov,prev;
    li tmp;
    cin>>N;
    prev=2;
    for(i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==1){
            if(prev==2)
                cout<<"2\n";
            else{
                cout<<"1\n";
            }
        }
        else{
            if(prev==1){
                if(A[i]%2==0){
                    prev=2;
                }
                else{
                    prev=1;
                }
            }
            else{
                if(A[i]%2==0){
                    prev=1;
                }
                else{
                    prev=2;
                }
            }
            cout<<prev<<"\n";
        }
    }


    return 0;
}
