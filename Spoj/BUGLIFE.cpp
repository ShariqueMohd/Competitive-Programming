#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<string.h>
 
#define vii vector< int >
#define vvi vector< vii >
 
using namespace std;
 
vii adj[2005];
bool flag=1;
int g[2005]={0};
 
 
bool dfs(int r){
    bool res = true;
    for(int i = 0; i < adj[r].size(); i++){
        int v = adj[r][i];
        if(g[v] == g[r]) return false;
        if(g[v] == 0){
            g[v] = -g[r];
            res = res and dfs(v);
        }
    }
    return res;
}
 
int main(){
    int t,n,m,i,k,x,y;
    scanf("%d",&t);
    for(k=1;k<=t;k++){
        scanf("%d%d",&n,&m);
        flag=1;
        for(i=0;i<=n;i++){
            g[i]=0;
            adj[i].clear();
        }
        while(m--){
           scanf("%d%d",&x,&y);
           adj[x].push_back(y);
           adj[y].push_back(x);
        }
        for(i=1;i<=n&&flag;i++){
            if(g[i]==0){
                g[i]=1;
                flag&=dfs(i);
            }
        }
 
        if(flag==1)
            printf("Scenario #%d:\nNo suspicious bugs found!\n",k);
        else
            printf("Scenario #%d:\nSuspicious bugs found!\n",k);
 
    }
 
    return 0;
}
