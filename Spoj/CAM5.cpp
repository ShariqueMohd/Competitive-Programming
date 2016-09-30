#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<string.h>
 
#define vi vector< int >
using namespace std;
 
const int MAX=100005;
vi G[MAX];
bool visit[MAX];
 
void initialise(int n){
    for(int i=0;i<=n;i++){
        G[i].clear();
    }
}
void dfs(int start){
    visit[start]=1;
 
    for(int i=0;i<G[start].size();i++){
        if(!visit[G[start][i]]){
            dfs(G[start][i]);
        }
    }
}
 
int main(){
    int tt,n,e,x,y,cc;
    scanf("%d",&tt);
    while(tt--){
        scanf("%d%d",&n,&e);
        initialise(n);
        for(int i=0;i<e;i++){
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        cc=0;
        memset(visit,0,sizeof(visit));
        for(int x=0;x<n;x++){
            if(!visit[x]){
                cc+=1;
                dfs(x);
            }
        }
 
        printf("%d\n",cc);
 
    }
 
 
    return 0;
}
