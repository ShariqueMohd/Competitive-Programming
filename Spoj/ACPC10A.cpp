#include <iostream>
 
using namespace std;
 
int main(){
    int a,b,c;
    while(1){
        cin>>a>>b>>c;
        if(a==0&&b==0&&c==0)
            break;
        int diff1,diff2;
        diff1=b-a;
        diff2=c-b;
        if(diff1==diff2){
            cout<<"AP\t"<<c+diff1<<"\n";
        }
        else{
            int r;
            r=b/a;
            cout<<"GP\t"<<r*c<<"\n";
        }
    }
    return 0;
}
