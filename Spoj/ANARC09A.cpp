#include<iostream>
#include<cstdio>
#include<string.h>
 
using namespace std;
 
int main(){
    int t=1,i,len,cnt,cntopen,cntclose;
    string s;
    while(1){
       cnt=0;
       cntopen=cntclose=0;
       cin>>s;
       if(s[0]=='-')
            break;
       len=s.length();
       for(i=0;i<len;i++){
            if(s[i]=='{')
                cntopen+=1;
            else if(s[i]=='}')
                cntclose+=1;
            if(cntclose>cntopen){
                s[i]='{';
                cnt+=1;
                cntopen+=1;
                cntclose-=1;
            }
      }
       if(cntopen>cntclose)
         cnt+=(cntopen-cntclose)/2;
      printf("%d. %d\n",t,cnt);
      t+=1;
    }
 
    return 0;
}
