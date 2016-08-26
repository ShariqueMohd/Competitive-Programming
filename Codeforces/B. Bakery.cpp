#include<iostream>
#include<vector>
#include<cstdio>
#include<string.h>
#include<utility>

#define pb push_back
#define mp make_pair
#define li long int
#define sc second
#define ft first
const int MAX=1e5+5;
const li T=(li)(1e9+7);

using namespace std;

vector<pair<int,li> > G[MAX];
bool p[MAX];
int A[MAX];

int main(){
    int N,M,K,x,y,i,j;
    li ans=T;
    li l;
    cin>>N>>M>>K;
    for(i=0;i<M;i++){
        cin>>x>>y>>l;
        G[x].pb(mp(y,l));
        G[y].pb(mp(x,l));
    }

    if(K==0){
        cout<<"-1\n";
        return 0;
    }
    for(i=0;i<K;i++){
        cin>>A[i];
        p[A[i]]=1;
    }

    for(i=0;i<K;i++){
        for(j=0;j<G[A[i]].size();j++){
            if(!p[G[A[i]][j].ft])
                ans=min(G[A[i]][j].sc,ans);
        }
    }
    if(ans!=T)
        cout<<ans<<"\n";
    else{
        cout<<"-1\n";
    }
}
