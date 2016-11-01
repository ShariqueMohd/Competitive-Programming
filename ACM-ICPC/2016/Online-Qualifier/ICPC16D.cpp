// By: @shariquemohd

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<utility>
#include<iomanip>
#include<map>
#include<set>
#include<bitset>

using namespace std;
//-----------------
#define ull unsigned long long int
#define lli long long int
#define li long int
#define ft first
#define sc second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pip pair<int,pii>

template<typename T> T gcd(T a, T b){return (b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
template<typename T> T mod(T a, T b) {return (a<b ? a : a%b);}
template<typename T> T mod_neg(T a, T b) {return ((a%b)+b)%b;}
template<typename T> T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T> T power(T e, T n, T m){T x=1%m,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template<typename T> T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T> T mod_inverse(T a, T n){T x,y;T d = extended_euclid(a, n, x, y);return (d>1?-1:mod_neg(x,n));}
//----------------------------------

const int MAX=750005;
const lli MOD = 1000000007;
bool isPresent[MAX];
lli cnt[MAX];
lli A[MAX];
vector<lli> G[MAX];

int main(){
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("As.out", "w", stdout);

    int T,N,i,j;
    lli large;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        memset(isPresent,0,sizeof(isPresent));
        memset(cnt,0,sizeof(cnt));
        large = -1;
        for(i=0;i<N;i++){
            scanf("%lld",&A[i]);
            if(large<A[i])
                large = A[i];
            isPresent[A[i]] = 1;
            cnt[A[i]] = 1;
        }
    /*
        cout<<"check:\n";
        for(i=1;i<=large;i++){
            cout<<i<<"\t"<<cnt[i]<<"\n";
        }
        cout<<"------------\n";*/

        sort(A,A+N);

        for(i=N-1;i>=0;i--){
            for(j=A[i]+A[i];j<=large;j+=A[i]){
                if(isPresent[j]){
                    G[A[i]].pb(j);
                }
            }
        }

        /*
        for(i=1;i<=6;i++){
            cout<<i<<":\t";
            for(j=0;j<G[i].size();j++){
                cout<<G[i][j]<<"\t";
            }
            cout<<"\n";
        }*/

        for(i=N-1;i>=0;i--){
            for(j=0;j<G[A[i]].size();j++){
                cnt[A[i]] += cnt[G[A[i]][j]];
            }
        }

        /*
        for(i=1;i<=large;i++){
            cout<<i<<"\t"<<cnt[i]<<"\n";
        }*/

        lli ans = 0LL;
        for(i=0;i<N;i++){
            ans +=cnt[A[i]];
            if(ans>MOD)
                ans -= MOD;
        }

        printf("%lld\n",ans);
        for(i=0;i<MAX;i++)
            G[i].clear();

    }


    return 0;
}
