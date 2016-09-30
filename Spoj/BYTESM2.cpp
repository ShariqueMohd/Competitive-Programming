#include<iostream>
 
using namespace std;
 
int a[105][105];
 
int maximum(int a,int b,int c){
  if(a>=b && a>=c)
    return a;
  if(b>=c)
    return b;
  return c;
}

int main(){
  int i,j,t,h,w,ans;
  cin>>t;
  while(t--){
    cin>>h>>w;
    for(i=1; i<=h; i++){
			for(j=1; j<=w; j++)
				cin>>a[i][j];
			a[i][j] = 0;
			for(j=1; j<=w; j++)
				a[i][j] += maximum(a[i-1][j-1], a[i-1][j], a[i-1][j+1]);
		}
    ans=a[h][1];
		for(i=2;i<=w;i++)
			ans=maximum(ans,a[h][i],0);
    cout<<ans<<endl;
  }
  return 0;
}
