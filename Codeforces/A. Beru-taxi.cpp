#include<iostream>
#include<math.h>
#include<algorithm>
#include<cstdio>
#include<iomanip>

using namespace std;

int main(){
    double a,b,N,x,y,v,tmin=1000000.0;
    cin>>a>>b;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x>>y>>v;
        
        double dist;
        dist=sqrt((a-x)*(a-x) + (b-y)*(b-y));
        
        tmin=min(tmin,(double)(dist*1.0000000/v));
    }
    cout<<fixed;
    cout<<setprecision(10)<<tmin*1.000000000;

    return 0;
}
