//merge sort algorithm
#include<iostream>
#include<cstdio>
#include<string.h>
 
#define li long int
using namespace std;
 
const int MAX=10005;
int arr[MAX],tmparr[MAX];
li m=10000007,ans=0;
 
void merge(int i,int k,int j){
    int st1=i,st2=k+1,ptr=0;
 
    while(st1<=k && st2<=j){
        if(arr[st1]>arr[st2]){
            tmparr[ptr]=arr[st2];
            st2+=1; ptr+=1;
            ans+=k-st1+1;
            ans%=m;
        }
        else{
            tmparr[ptr]=arr[st1];
            st1+=1; ptr+=1;
        }
    }
 
    while(st1<=k){
        tmparr[ptr]=arr[st1];
        st1+=1;  ptr+=1;
    }
 
    while(st2<=j){
        tmparr[ptr]=arr[st2];
        st2+=1; ptr+=1;
    }
 
    for(int z=i;z<=j;z++){
        arr[z]=tmparr[z-i];
    }
 }
 
void mergesort(int lo,int hi){
    if(lo==hi)
        return;
    int mid=(hi+lo)/2;
    mergesort(lo,mid);
    mergesort(mid+1,hi);
    merge(lo,mid,hi);
}
int main(){
    int t,n,i,c=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        ans=0;
        mergesort(0,n-1);
        c+=1;
        printf("Case %d: %d\n",c,ans);
 
    }
 
    return 0;
}
