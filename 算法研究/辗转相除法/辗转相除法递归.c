#include<stdio.h>
int gcd(int m,int n){
	//����ֱ����Ŀ����� 
    return n==0?m:gcd(n,m%n);
}
int main(){
    int p,n,m;
    scanf("%d",&p);
    while(p--){
            scanf("%d %d",&m,&n);
            if(gcd(m,n)==1)
                printf("NO\n");
            else
                printf("YES\n");
        }
    return 0;
}
