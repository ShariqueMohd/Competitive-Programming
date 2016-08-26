#include<iostream>
#include<cstdio>
#include<utility>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define ll long long int
#define ppl pair<ll,ll>
#define vpl vector<ppl>

using namespace std;

ll num;
char S[20];
typedef struct $ ss;

struct ${
    int freq=0;
    ss* left;   // for 0
    ss* right;  // for 1
};

void add(ss *head,ll a,ll cnt){
    if(cnt==-1)
        return;
    if((a>>cnt)&1){
        if(head->right == NULL){
            head->right = (ss *)malloc(sizeof(ss));
            head->right->right=NULL;
            head->right->left=NULL;
            if(cnt==0){
                head->right->freq = 1;
            }
        }
        else{
            if(cnt==0)
                head->right->freq += 1;
        }
        add(head->right,a,cnt-1);
    }
    else{
        if(head->left == NULL){
            head->left = (ss *)malloc(sizeof(ss));
            head->left->right = NULL;
            head->left->left = NULL;
            if(cnt==0){
                head->left->freq=1;
            }
        }
        else{
            if(cnt==0)
                head->left->freq +=1;
        }
        add(head->left,a,cnt-1);
    }
}

void rem(ss *head,ll a,ll cnt){
    if(cnt==-1)
        return;
    if(cnt==0)
        head->freq-=1;
    if((a>>cnt)&1){
        rem(head->right,a,--cnt);
    }
    else{
        rem(head->left,a,--cnt);
    }
}

void query(ss *head,ll a,ll cnt){
    if(cnt==-1)
        return;
    if((a>>cnt)&1){
        if(head->left!=NULL){
            num+=(ll)pow(2,cnt);
            query(head->left,a,--cnt);
        }
        else{
            query(head->right,a,--cnt);
        }
    }
    else{
        if(head->right!=NULL){
            num+=(ll)pow(2,cnt);
            query(head->right,a,--cnt);
        }
        else{
            query(head->left,a,--cnt);
        }
    }
}


int main(){
    int Q;
    ll N,ans,len;
    char ch;
    cin>>Q;
    ss *x=(ss *)malloc(sizeof(ss));
    x->left=NULL;
    x->right=NULL;
    while(Q--){
        cin>>ch>>N;
        len=strlen(S);

        if(ch=='+'){
            add(x,N,31);
        }
        else if(ch=='-'){
            rem(x,N,31);
        }
        else if(ch=='?'){
            num=0;
            query(x,N,31);
            printf("%lld\n",num);
        }
    }

    return 0;
}

