#include<iostream>
#include<string.h>

using namespace std;

string S;

int main(){
    int N,i;
    cin>>S;
    if(S[0]=='a' || S[0]=='h'){
        if(S[1]=='1' || S[1]=='8'){
            cout<<"3\n";
        }
        else{
            cout<<"5\n";
        }
    }
    else{
        if(S[1]=='1' || S[1]=='8'){
            cout<<"5\n";
        }
        else{
            cout<<"8\n";
        }
    }


    return 0;
}
