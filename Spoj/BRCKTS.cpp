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
const int MAX=30005;
 
struct T{
    int sum;
    int left;
    int right;
}ST[4*MAX];
char S[MAX];
 
void build(int node,int start,int last){
    if(start==last){
        if(S[start]=='('){
            ST[node].sum=1;
            ST[node].right=1;
            ST[node].left=0;
        }
        else{
            ST[node].sum=-1;
            ST[node].right=0;
            ST[node].left=1;
        }
        return;
    }
 
    int mid=(start+last)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,last);
 
    int temp;
    ST[node].sum=ST[2*node].sum + ST[2*node+1].sum;
    temp=ST[2*node].right-ST[2*node+1].left;
    if(temp<0){
        ST[node].left=(-1)*temp + ST[node*2].left;
        ST[node].right=ST[2*node+1].right;
    }
    else{
        ST[node].left=ST[2*node].left;
        ST[node].right=temp + ST[2*node+1].right;
    }
}
 
void update(int node,int ind,int start,int last){
    if(start==last){
        if(ST[node].sum==1){
            ST[node].sum=-1;
            ST[node].left=1;
            ST[node].right=0;
        }
        else{
            ST[node].sum=1;
            ST[node].left=0;
            ST[node].right=1;
        }
        return;
    }
    int mid=(start+last)/2;
    if(ind<=mid){
        update(node*2,ind,start,mid);
    }
    else{
        update(node*2+1,ind,mid+1,last);
    }
 
    int temp;
    ST[node].sum=ST[2*node].sum + ST[2*node+1].sum;
    temp=ST[2*node].right-ST[2*node+1].left;
    if(temp<0){
        ST[node].left=(-1)*temp + ST[node*2].left;
        ST[node].right=ST[2*node+1].right;
    }
    else{
        ST[node].left=ST[2*node].left;
        ST[node].right=temp + ST[2*node+1].right;
    }
}
 
bool query(){
    if(ST[1].sum!=0){
        return false;
    }
    if(ST[1].right!=0 || ST[1].left!=0){
        return false;
    }
    return true;
}
 
 
 
int main(){
    int T,N,M,K;
    bool flag;
    for(int i=1; i<=10; i++){
        scanf("%d",&N);
        scanf("%s",S);
        scanf("%d",&M);
        build(1,0,N-1);
        printf("Test %d:\n",i);
        while(M--){
            scanf("%d",&K);
            if(K==0){
                flag=query();
                if(flag==1){
                    printf("YES\n");
                }
                else{
                    printf("NO\n");
                }
            }
            else{
                update(1,K-1,0,N-1);
            }
        }
    }
    return 0;
}
