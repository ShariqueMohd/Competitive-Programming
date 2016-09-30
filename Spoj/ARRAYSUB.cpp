#include<iostream>
#include<cstdio>
#include<algorithm>
 
using namespace std;
 
const int MAX=1000005;
int A[MAX];
int ST[4*MAX];
 
void build(int node,int lo,int hi){
    if(lo==hi){
        ST[node]=A[lo];
    }
    else{
        int mid=(hi+lo)/2;
        build(2*node,lo,mid);
        build(2*node+1,mid+1,hi);
        ST[node]=max(ST[2*node],ST[2*node+1]);
    }
}
 
int query(int node,int beg,int last,int lo,int hi){
    if(hi<beg || last<lo){
        return 0;
    }
    if(lo<=beg && hi>=last){
        return ST[node];
    }
 
    int mid=(beg+last)/2;
    int p1=query(2*node,beg,mid,lo,hi);
    int p2=query(2*node+1,mid+1,last,lo,hi);
    return max(p1,p2);
}
 
int main(){
    int N,K,i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    build(1,0,N-1);
    scanf("%d",&K);
 
    int l=0,r=K-1;
    for(;r<N;r++,l++){
        printf("%d ",query(1,0,N-1,l,r));
    }
 
    return 0;
}
