#include<iostream>
#include<cstdio>
 
#define ull unsigned long long int
using namespace std;
 
int main(){
    ull n,i,sum,t,num;
    cin>>t;
    while(t--){
        cin>>n;
        sum=0;
        for(i=0;i<n;i++){
            cin>>num;
            sum=(sum+num)%n;
        }
        if(sum%n==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
