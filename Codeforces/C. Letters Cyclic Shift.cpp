#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

string s;
int main(){
    int N,i=0,j;
    cin>>s;
    N=s.length();
    
    while(s[i]=='a' & i<N){
            i+=1;
    }
    
    if(i==N){
        for(i=0;i<N-1;i++){
            cout<<s[i];
        }
        cout<<"z\n";
    }
    else{
        for(j=0;j<i;j++){
            cout<<s[j];
        }

        for(j=i;j<N;j++){
            if(s[j]=='a')
                break;
            else{
                int ind = s[j]-'a';
                cout<<(char)('a'+ind-1);
            }
        }

        for(i=j;i<N;i++){
            cout<<s[i];
        }

    }

    return 0;
}
