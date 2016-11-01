// By: @shariquemohd

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<utility>
#include<iomanip>
#include<map>
#include<set>
#include<bitset>

using namespace std;
//-----------------
#define ull unsigned long long int
#define lli long long int
#define li long int
#define ft first
#define sc second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pip pair<int,pii>

template<typename T> T gcd(T a, T b){return (b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
template<typename T> T mod(T a, T b) {return (a<b ? a : a%b);}
template<typename T> T mod_neg(T a, T b) {return ((a%b)+b)%b;}
template<typename T> T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T> T power(T e, T n, T m){T x=1%m,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template<typename T> T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T> T mod_inverse(T a, T n){T x,y;T d = extended_euclid(a, n, x, y);return (d>1?-1:mod_neg(x,n));}
//----------------------------------

const int MAX=100005;
li A[MAX];

int main(){
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("As.out", "w", stdout);

    int N,T,i,zero,neg,pos;
    cin>>T;
    while(T--){
        cin>>N;
        zero = neg = pos = 0;
        for(i=0;i<N;i++){
            cin>>A[i];
            if(A[i] == 0)
                zero += 1;
            if(A[i] == 1)
                pos += 1;
            if(A[i] == -1)
                neg += 1;
        }

        if(neg == 0){
            if((zero + pos == N-1) || (zero + pos) == N){
                cout<<"yes\n";
            }
            else{
                cout<<"no\n";
            }
        }
        else {
            if(neg==1){
                if(neg + pos + zero == N){
                    cout<<"yes\n";
                }
                else{
                    cout<<"no\n";
                }
            }
            else{
                if(pos>0){
                    if(zero + neg + pos == N){
                        cout<<"yes\n";
                    }
                    else{
                        cout<<"no\n";
                    }
                }
                else{
                    cout<<"no\n";
                }
            }
        }



    }






    return 0;
}
