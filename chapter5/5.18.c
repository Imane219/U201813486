/*������ѭ������kλ ʱ�临�Ӷ�λO��N�� ֻ��һ��Ԫ�ش�С�ĸ��Ӵ洢

��һ��1234567 �����������������3λ
    1.�������λ��567�����ã�765��  1234765
    2.��ʣ�����֣�1234�����ã�4321�� 4321765
    3.�������� 5671234

    ע����k>=Nʱ���ƶ�kλ�����ƶ�k%Nλ

*/

#include <stdio.h>
#include <stdlib.h>

#define N 7

void reverse(int *a,int i,int j)//��a[i]��a[j]��������
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
