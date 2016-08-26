#include<iostream>
#include<string.h>

using namespace std;
char ch;

int main(){
    int N,M,flag=0;
    cin>>N>>M;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin>>ch;
            if(ch!='W' && ch!='B')
                flag=1;
        }
    }

    if(flag){
        cout<<"#Color\n";
    }
    else{
        cout<<"#Black&White\n";
    }


}
