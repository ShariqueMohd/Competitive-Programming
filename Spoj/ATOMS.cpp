#include <stdio.h>
 
int main(){
    int p;
    long long n, k, m, count;
    double mul;
    scanf("%d", &p);
    while (p--){
        scanf("%lld %lld %lld", &n, &k, &m);
        mul = n;
        count = 0;
        while (mul <= m){
            count++;
            mul *= k;
        }
        if (count > 0)
            printf("%lld\n", count-1);
        else
            printf("0\n");
    }
    return 0;
} 
