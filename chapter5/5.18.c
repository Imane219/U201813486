/*将数组循环后移k位 时间复杂度位O（N） 只用一个元素大小的附加存储

法一：1234567 按如下三个步骤后移3位
    1.将最后三位（567）逆置（765）  1234765
    2.将剩下数字（1234）逆置（4321） 4321765
    3.整体逆置 5671234

    注：当k>=N时，移动k位就是移动k%N位

*/

#include <stdio.h>
#include <stdlib.h>

#define N 7

void reverse(int *a,int i,int j)//从a[i]到a[j]进行逆置
{
    for(;i<j;i++,j--)
    {
        int temp = a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}

int main()
{
    int a[N],k;
    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);

    scanf("%d",&k);
    k=k%N;

    reverse(a,N-k,N-1);
    reverse(a,0,N-k-1);
    reverse(a,0,N-1);

    for(int i=0;i<N;i++)
        printf("%d ",a[i]);

    return 0;
}
