/*
辗转相除法求两个数的公约数，最大公约数。、

兔子必须藏在其中一个洞中。 狼以逆时针方向搜索兔子。 他第一个进入的洞是一个用0签名的洞。
然后，他将每m个洞进入一个洞。 例如，m = 2和n = 6，狼将进入带符号0,2,4,0的孔。 
如果兔子躲在标有1,3或5的孔中，它将存活。 因此，我们将这些漏洞称为安全漏洞。

 
该题目的原理是通过证明他们的最大公约数是1说明兔子没有洞可以躲。不是1的话说明有洞可以躲。 
*/ 
#include<stdio.h>

//函数 
int common_divisor(int a,int b);

int main(){
	int n;
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",common_divisor(a,b));
	return 0;
}

//求公约数 
int common_divisor(int a,int b){
	//取两者中较大 
	int t;
	if(a<b){
		t=a;
		a=b;
		b=t;
	}
	while(b){
		t=b;
		b=a%b;
		a=b;
	}
	return t;	 
}



