#include <iostream>

using namespace std;

int main(){

    int d,t,m,n,m1,n1,add,addrev1,addrev;
    cin>>t;
    while(t--){
      add=0;
      cin>>m>>n;
      while(m){
        d=m%10;
        add+=d;
        m=m/10;
        if(m!=0){
          add*=10;
        }
      }
      m1=add;

      add=0;
      while(n){
        d=n%10;
        add+=d;
        n=n/10;
        if(n!=0){
          add*=10;
        }
      }
      n1=add;

      addrev1=m1+n1;
      add=0;
      while(addrev1){
        d=addrev1%10;
        add+=d;
        addrev1=addrev1/10;
        if(addrev1!=0){
          add*=10;
        }
      }
      addrev=add;
      cout<<addrev<<endl;
    }
    return 0;
}
