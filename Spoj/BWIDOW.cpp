// By: @shariquemohd
 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<utility>
 
#define ull unsigned long long int
#define lli long long int
#define li long int
#define ft first
#define sc second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pip pair<int,pii>
 
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template <typename T> T InverseEuler(T a, T m){return (a==1? 1:power(a, m-2, m));}
template <typename T> T gcd(T a, T b){return __gcd(a,b);}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
 
using namespace std;
const int MAX=1005;
 
struct node{
    li IR,OR;
    int ind;
}V[MAX];
 
li AOR[MAX];
 
bool cmp(struct node a,struct node b){
    if(a.IR<b.IR)
        return true;
    if(a.IR>b.IR)
        return false;
    if(a.IR==b.IR){
        if(a.OR<b.OR)
            return true;
        return false;
    }
}
 
int main(){
    int N,T;
    li maxIR,maxOR,i,tmpIR,tmpOR;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(i=0;i<N;i++){
            scanf("%ld%ld",&tmpIR,&tmpOR);
            V[i].IR=tmpIR;
            V[i].OR=tmpOR; AOR[i]=tmpOR;
            V[i].ind=i;
        }
        sort(V,V+N,cmp);
        sort(AOR,AOR+N);
 
        maxOR = AOR[N-1];
        if(V[N-1].OR == maxOR){
            maxOR=AOR[N-2];
        }
 
        if(V[N-1].IR >= maxOR){
            printf("%d\n",V[N-1].ind+1);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}
