#include<iostream>
#include<string.h>

using namespace std;

const int MAX=55;
string S[MAX];
bool visited[MAX][MAX],flag=0;
int T[MAX][MAX];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}},N,M;

void dfs(int x,int y,int Time,int px,int py){
    
    if(visited[x][y]){
        if(T[px][py]-T[x][y]+1>=4){
            flag=1;
        }
        return;
    }
    visited[x][y]=1;
    T[x][y]=Time+1;

    for(int i=0;i<4;i++){
        int xco=x+dir[i][0],yco=y+dir[i][1];
        if(xco>=0 && xco<N && yco>=0 && yco<M && S[x][y]==S[xco][yco]){
            dfs(xco,yco,Time+1,x,y);
        }
    }
}

int main(){
    int i,j;
    cin>>N>>M;
    for(i=0;i<N;i++){
        cin>>S[i];
    }
    
    for(i=0;i<N && !flag;i++){
        for(j=0;j<M && !flag;j++){
            if(!visited[i][j]){
                dfs(i,j,0,i,j);
            }
        }
    }
    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}
