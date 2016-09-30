#include<iostream>

#define lli long long int
using namespace std;
 
int main(){
    lli thirdlast,third,n=0,sum,diff=0,a;
    int t;
    cin>>t;
    while(t--){
        cin>>third>>thirdlast>>sum;
        n=2*sum;
        n/=(third+thirdlast);
        cout<<n<<endl;
        diff=thirdlast-third;
        diff/=n-5;
        a=third-2*diff;
        int temp=0,next;
        for(int i=0;i<n;i++){
          next=a;
          temp=diff*i;
          next+=temp;
          cout<<next<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
