

#include <stdio.h>
#include <stdlib.h>

/*求一元多项式的和

 *参数说明：
       n —— 多项式最高次数
       x —— 变元（待输入）
       p —— 多项式的值
       a —— 存放各个多项式系数的数组的首地址

       时间复杂度O(n)
       循环内的两条语句执行次数为n，其余语句执行次数为1
*/

int main()
{
    int i,n,x;
    printf("please input n,x");//提示输入
    scanf("%d%d",&n,&x);//input n and x

    int *a = (int *)malloc((n+1)*sizeof(int));//用malloc创造数粗存a0到an
    printf("please input a[n]");//提示输入
    scanf("%d",&a[n]);//提示输入an
    long p = a[n];//设定p的初值an
    printf("please get the a[n-1] to a[0]");//提示逆序输入an-1到a0

    for(i=n-1;i>=0;i--)
    {
        scanf("%d",&a[i]);//逆序输入a
        p = p*x+a[i];//计算多项式的和p
    }
    printf("P = %ld",p);//打印p的值
    return 0;
}
