/*
题目：
对于任意大于 1 的自然数 n，总是可以拆分成若干个小于 n
的自然数之和。
现请你编写程序求出 n
的所有拆分。
输入格式
输入文件共一行，包含一个自然数，即要拆分的自然数 n(1≤n≤20)
输出格式
输出文件有若干行，每行包含一个等式，即代表一种可行的拆分（格式与顺序参见样例）。


5

5=1+1+1+1+1
5=1+1+1+2
5=1+1+3
5=1+2+2
5=1+4
5=2+3

*/

/*
首先分析题意，不难想到这是一道深度优先搜索的题目，
5=4+1，而4=3+1=2+2=1+1+1+1等，既然是dfs首先想到的就是一个递归。
构建递归算法。
递归的过程与递归的出口。
传入的i与所求的sum相等便为出口。 
 
*/

#include<stdio.h>
#include<stdlib.h>


#define MAXN 22 
int a[MAXN];
 
int n;//由于输出需要用到n，所以使用全局变量，否则可以不全局
 
void dfs(int sum, int len, int start) {
    if (n==sum) {
        printf("%d=%d",n,a[0]);
        for (int i=1; i<len; i++)
            printf("+%d",a[i]);
        printf("\n");
        return;
    }
    for (int i=1; i<n; i++)
        if (sum+i<=n && i>=start) {
            a[len]=i;
            len++;
            dfs(sum+i, len, i);
            len--;
        }
}
 
int main() {

	scanf("%d",&n);
    dfs(0,0,1);
    return 0;
}
