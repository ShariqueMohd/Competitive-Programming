#include<iostream>
#include<algorithm>
#include<cstdio>
 
#define lli long long int
using namespace std;
 
lli a[20005];
 
int main(){
  int t,n,k,i;
  lli diff;
  cin>>t;
  while(t--){
    cin>>n>>k;
    for(i=0;i<n;i++){
       cin>>a[i];
    }
    sort(a,a+n);
 
    diff=a[k-1]-a[0];
    for(i=1;i+k-1<n;i++){
      diff=min(diff,a[i+k-1]-a[i]);
    }
    cout<<diff<<endl;
  }
 
  return 0;
}
