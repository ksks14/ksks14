/*
排序是一种很频繁的计算任务。一个实际的例子是，当我们给某项竞赛的优胜者按金银铜牌排序的时候。在这个任务中可能的值只有三种1，2和3。我们用交换的方法把他排成升序的。
写一个程序计算出，计算出的一个包括1、2、3三种值的数字序列，排成升序所需的最少交换次数。
输入第1行为类别的数量N（1≤N≤1000）
输入第2行到第N+1行，每行包括一个数字（1或2或3）。
输出包含一行，为排成升序所需的最少交换次数

9
2
2
1
3
3
3
2
3
1
*/


/*
这是一道经典的贪心算法的题目。
所谓贪心思想即将整个问题分成很多个小问题，对每个小问题求最终解，将这些解结合起来，就构成了整个大问题的解。
不断的求局部最优，并不能确定最终的解就是最优的，所以贪心算法并不是在任意时间都是适用的。

对整个题目进行解读，其实，就是说，我们怎么样能交换最少的次数，让这个序列升序。可以想到，如果要交换最少的次
数，那就要尽量做到让他们每一步交换尽量都到自己最终的位置，而且还有一点要考虑，即，如果我们把全部的1和全部
的2已经排好了，那全部的3必然也已经排好了。 
*/


#include<stdio.h>
#include<stdlib.h>
#define maxsize 100001

/*
swap函数在c语言初始学习指针中必学的函数，交换两个变量的值。
在一般的情况下，传参传入形参，并不能对传入数值的实值做改变，等于传入是copy了几个新的值，所有要想实现值转
化，就需要让形参的地址和实参的地址一样，这样的话就可以通过改变地址，改变原先的值，因此传入两个值的地址。 
*/
void swap(int *a,int *b);


int main(){
	int n,count_1=0,count_2=0,count=0;
	/*
	为什么要初始化，因为在一些编译环境中，数组是不会初始化的，这样访问数组数据时，可能会出现乱码等一些意外
	的情况。进而使整个程序出现无法预料到的错误。 
	*/
	int a[maxsize]={0};
	scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1)	count_1++;
        if(a[i]==2)	count_2++;
    }
    for(int i=0;i<count_1;i++)
    {
        if(a[i]==2)
            for(int j=count_1;j<n;j++)
                if(a[j]==1)
                {
                    swap(&a[i],&a[j]);
                    count++;
                    break;
                }
        if(a[i]==3)
            for(int j=n-1;j>=count_1;j--)
                if(a[j]==1)
                {
                    swap(&a[i],&a[j]);
                    count++;
                    break;
                }

    }
    for(int i=count_1;i<count_1+count_2;i++)
        if(a[i]==3)
            for(int j=count_1+count_2;j<n;j++)
                if(a[j]==2)
                {
                    swap(&a[i],&a[j]);
                    count++;
                    break;
                }
    
	
	printf("%d\n",count);
}

//交换函数。 
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
