#include<iostream>
#include<algorithm>

#define lli long long int
#define m 1e9
using namespace std;

const int MAX = 3e5+5;
lli A[MAX];

int main(){
    lli N,i,sum=0,x;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>A[i];
        //sum += (x+m);
    }
    sort(A,A+N);

    cout<<A[((N-1)>>1)];

    return 0;
}
