#include<iostream>
 
using namespace std;
 
int main(){
  int n,i,flag=1,sum,temp=0;
  cin>>n;
  sum=n;
  for(i=1;flag==1;i++){
    if((n/i)>i){
      temp=n/(i+1);
      temp-=i;
      if(temp>0){
          sum+=temp;  //(n/(i+1)-i>0)
      }
    }
    else
        flag=0;
  }
  cout<<sum;
  return 0;
}
