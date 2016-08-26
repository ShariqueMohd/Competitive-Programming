#include<iostream>
#include<algorithm>
#include<map>

#define lli long long int

using namespace std;

const int MAX=1e5+5;
lli N,A[MAX],x,ans=0;
map<lli,lli> M;

int main() {
	scanf("%I64d",&N);
    for (lli i=0;i<N;i++) {
		scanf("%I64d",&A[i]);
		x=1;
		while (x<=2e9) {
			if (x>A[i])
				ans+=M[x-A[i]];
			x<<=1;
		}
		M[A[i]]++;
	}
	cout << ans;
}
