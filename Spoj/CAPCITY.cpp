#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
 
#define pb push_back
using namespace std;
 
const int MAX=200005;
vector<int> G[MAX],REVG[MAX],St;
bool visit[MAX];
int comp[MAX],in[MAX];
 
void DFS1(int u){
    visit[u]=1;
 
    for(int v=0;v<G[u].size();v++){
        if(!visit[G[u][v]]){
            DFS1(G[u][v]);
        }
    }
    St.pb(u);
}
 
void DFS2(int u,int C){
    visit[u]=0;
    comp[u]=C;
 
    for(int v=0;v<REVG[u].size();v++){
        if(visit[REVG[u][v]]){
            DFS2(REVG[u][v],C);
        }
    }
}
 
int main(){
    int i,j,cnt,N,M,x,y,lim,Component;
    scanf("%d%d",&N,&M);
 
    for(i=0; i<M; i++){
        scanf("%d%d",&x,&y);
        G[y].pb(x);
        REVG[x].pb(y);
    }
 
 
    for(i=1; i<=N; i++){
        if(!visit[i]){
            DFS1(i);
        }
    }
 
    Component=0;
 
    for(i=St.size()-1; i>=0; i--){
        if(visit[St[i]]){
            //cout<<i<<" ";
            DFS2(St[i],Component++);
        }
    }
    
    lim=Component;
    for(i=1; i<=N; i++){
        for(j=0; j<G[i].size(); j++){
            if(comp[i]!=comp[G[i][j]]){
                in[ comp[G[i][j]] ]+=1;
            }
        }
    }
 
    cnt=0;
    for(i=0; i<lim; i++){
        if(in[i]==0){
            cnt+=1;
        }
    }
 
    if(cnt>1 || cnt==0){
        printf("0\n");
    }
    else{
        cnt=0;
        for(i=1; i<=N; i++){
            if(in[comp[i]]==0){
                cnt+=1;
            }
        }
        printf("%d\n",cnt);
 
        for(i=1; i<=N; i++){
            if( in[comp[i]]==0){
                printf("%d ",i);
            }
        }
        printf("\n");
    }
 
 
    return 0;
}
