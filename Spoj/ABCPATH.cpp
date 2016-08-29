#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
 
using namespace std;
 
const int MAX=55;
char S[MAX][MAX],ARR[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
bool visit[MAX][MAX];
int ans,N,M;
int x[8]={-1,-1,-1,0,0,1,1,1};
int y[8]={-1,0,1,-1,1,-1,0,1};
 
void dfs(int i,int j,int cnt){
    if(visit[i][j])
        return;
    ans=max(ans,cnt);
    visit[i][j]=1;
    for(int z=0;z<8;z++){
        int X=i+x[z];
        int Y=j+y[z];
        if(X>=0 && X<N && Y>=0 && Y<M ){
            int num=S[i][j]-'A';
            if(num==25)
                continue;
            if(S[X][Y]==ARR[num+1]){
                dfs(X,Y,cnt+1);
            }
        }
    }
}
 
 
int main(){
    int tt=0;
 
    while(1){
        scanf("%d%d",&N,&M);
        if(N==0 && M==0)
            break;
        ans=0;
        for(int i=0;i<N;i++)
            scanf("%s",S[i]);
 
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(S[i][j]=='A'){
                    memset(visit,0,sizeof(visit));
                    dfs(i,j,1);
                }
            }
        }
        tt+=1;
        printf("Case %d: %d\n",tt,ans);
    }
 
    return 0;
}
