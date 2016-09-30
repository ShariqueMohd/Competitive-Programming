#include<iostream>
#include<math.h>
 
using namespace std;
 
int main(){
  long long int n;
  double tmp,fracpart,intpart;
    while(1){
      cin>>n;
      if(n==-1)
        break;
      n=(4*n-1)/3;
      tmp=sqrt(n);
      fracpart=modf(tmp, &intpart);
      if(fracpart==0)
        cout<<"Y\n";
       else
        cout<<"N\n";
    }
    return 0;
}
