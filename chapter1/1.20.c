

#include <stdio.h>
#include <stdlib.h>

/*��һԪ����ʽ�ĺ�

 *����˵����
       n ���� ����ʽ��ߴ���
       x ���� ��Ԫ�������룩
       p ���� ����ʽ��ֵ
       a ���� ��Ÿ�������ʽϵ����������׵�ַ

       ʱ�临�Ӷ�O(n)
       ѭ���ڵ��������ִ�д���Ϊn���������ִ�д���Ϊ1
*/

int main()
{
    int i,n,x;
    printf("please input n,x");//��ʾ����
    scanf("%d%d",&n,&x);//input n and x

    int *a = (int *)malloc((n+1)*sizeof(int));//��malloc�������ִ�a0��an
    printf("please input a[n]");//��ʾ����
    scanf("%d",&a[n]);//��ʾ����an
    long p = a[n];//�趨p�ĳ�ֵan
    printf("please get the a[n-1] to a[0]");//��ʾ��������an-1��a0

    for(i=n-1;i>=0;i--)
    {
        scanf("%d",&a[i]);//��������a
        p = p*x+a[i];//�������ʽ�ĺ�p
    }
    printf("P = %ld",p);//��ӡp��ֵ
    return 0;
}
