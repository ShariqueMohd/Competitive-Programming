    #include<iostream>
    #include<algorithm>

    #define lli long long int
    using namespace std;

    lli D,K,A,B,T;

    int main(){
        lli ans;
        cin>>D>>K>>A>>B>>T;
        if(D<=K){
            ans=D*A;
            cout<<ans;
            return 0;
        }
        if(T+A*K>B*K){
            ans=K*A+(D-K)*B;
            cout<<ans;
            return 0;
        }
        lli cnt=(lli)(D/K);
        ans=K*cnt*A + T*(cnt-1) + min(T+(D%K)*A,(D%K)*B);
        cout<<ans;

        return 0;
    }
