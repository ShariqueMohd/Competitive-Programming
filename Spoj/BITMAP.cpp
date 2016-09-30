#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <vector>
 
#define INF 10000
 
using namespace std;
 
int a[190][190];
int m,n;
 
int BFS(int i,int j){
	queue<int> q;
	q.push(i);
	q.push(j);
 
	a[i][j]=0;
 
	while(!q.empty()){
		int x= q.front();
		q.pop();
		int y= q.front();
		q.pop();
 
		int dist= a[x][y]+1;
		
		if(y-1>=0 && dist < a[x][y-1]){
			q.push(x);
			q.push(y-1);
			a[x][y-1]=dist;
		}
		
		if(y+1<n && dist < a[x][y+1]){
			q.push(x);
			q.push(y+1);
			a[x][y+1]= dist;
		}
 
		if(x-1>=0 && dist < a[x-1][y]){
			q.push(x-1);
			q.push(y);
			a[x-1][y]= dist;
		}
 
		if(x+1<m && dist < a[x+1][y]){
			q.push(x+1);
			q.push(y);
			a[x+1][y]= dist;
		}
	}
}
 
int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
		vector< pair<int,int> > vc;
		scanf("%d%d",&m,&n);
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				char ch;
				cin>>ch;
 
				if(ch=='1'){
					a[i][j]= -INF;
					vc.push_back(make_pair(i,j));
				}
				else 
					a[i][j]=INF;
			}
 
		for(int i=0;i<vc.size();i++)
			BFS(vc[i].first,vc[i].second);
 
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
		printf("\n");
	}
} 
