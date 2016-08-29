#include<iostream>
#include<algorithm>
 
using namespace std;
 
int n,c;
unsigned long int a[100001];
 
int func(unsigned long int x){
   int cows=1,k;
   unsigned long int lastpos=a[0];
   for(k=1;k<n;k++){
        if((a[k]-lastpos)>=x){
            cows+=1;
               if(cows==c)
                    return 1;
            lastpos=a[k];
        }
 
    }
    return 0;
}
int bsearch(){
  unsigned long int start=0,last=a[n-1];
    while(start<last){
		unsigned long int mid=start+(last-start)/2;
		if(func(mid)==1)
		    start=mid+1;
		else
		    last=mid;
		}
		return start-1;
 
}
 
int main(){
    int t,i;
    cin>>t;
        while(t--){
          cin>>n>>c;
          for(i=0;i<n;i++){
            cin>>a[i];
          }
          sort(a,a+n);
         cout<<bsearch()<<endl;
 
        }
 
    return 0;
}
