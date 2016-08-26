#include<iostream>
#include<cstdio>

using namespace std;

const int MAX = 105;

int P[MAX],vis[MAX],present[MAX];
int N,M;

void init(){
    for(int i = 0; i < MAX; i++){
        P[i] = i;
    }
}

int root(int x){

    while(P[x] != x)
        x = P[x];

    return P[x];
}

void add(int x, int y){

    int px = root(x);
    int py = root(y);
    if (px != py)
        if(px < py)
            P[x] = y;
        else
            P[y] = x;

}

void trav(int x){

    while(P[x] != x){
        //cout<< x <<" ";
        vis[x] = 1;
        x = P[x];
    }
    vis[x] = 1;

}
int main(){
    int i,j,K,x,y;
    cin >> N >> M;
    init();

    for(i = 1; i <= N; i++){
        cin >> K;
        if(K == 0)
            continue;
        cin>> x; present[x] = 1;
        for(j = 1; j < K; j++){
            cin >> y; present[y] = 1;
            add(x, y);
        }
    }
    int cnt = 0;

    for( i = 1; i <= N; i++){
        if(present[i] && !vis[i]){
            trav(i);
            cnt += 1;
        }
    }


    cout << cnt-1 << "\n";
    for(i=1;i<=N;i++){
        cout<<P[i]<<" ";

    }
    return 0;
}
