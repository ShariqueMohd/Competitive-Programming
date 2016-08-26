#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int MAXN = 1e3+5;
const int MAXQ = 1e5+5;

int N,M,Q,F[MAXN][MAXN],ans,SUM[MAXN];
int query[MAXQ][3],res[MAXQ];
vector<int> v[MAXQ];

void place(int x, int y){
    F[x][y] = !F[x][y];
    ans += 1, SUM[x] += 1;
}

void rem(int x, int y){
    F[x][y] = !F[x][y];
    ans -= 1, SUM[x] -= 1;
}

void invert(int x){
    F[x][0] = !F[x][0];
    ans -= SUM[x];
    SUM[x] = M-SUM[x];
    ans += SUM[x];
}

void dfs(int k){
    int o = 0, t, x, y, i;
    t = query[k][0]; x = query[k][1]; y = query[k][2];

    if(t == 1){
        if(F[x][y] ^ F[x][0] ^ 1)
            place(x,y);
        else
            o = 1;
    }
    else if(t == 2){
        if(F[x][y] ^ F[x][0])
            rem(x,y);
        else
            o = 1;
    }
    else if(t == 3){
        invert(x);
    }
    res[k] = ans;

    for(i = 0; i < v[k].size(); i++){
        dfs(v[k][i]);
    }

    if(o)
        return;
    if(t == 1)
        rem(x,y);
    else if(t == 2)
        place(x,y);
    else if(t == 3)
        invert(x);
}

int main(){
    int x,y,i;
    cin>>N>>M>>Q;
    for(i = 1; i <= Q; i++){
        cin>>query[i][0]>>query[i][1];

        if(query[i][0] < 3)
            cin>>query[i][2];

        if(query[i][0]<4)
            v[i-1].push_back(i);
        else
            v[query[i][1]].push_back(i);
    }

    dfs(0);
    for(i = 1; i <= Q; i++){
        cout<<res[i]<<"\n";
    }

    return 0;
}
