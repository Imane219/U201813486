/*������������XYZ����XYZ���ʱ���Ӵ�С����


����˵����XYZ ���� �����������
          temp ���� �ڽ���XYZֵʱ�𱣴�ֵ������
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X,Y,Z,temp;
    scanf("%d%d%d",&X,&Y,&Z);//����XYZ
    if(X<Y)//ʹX>Y
    {
        temp = X;
        X = Y;
        Y = temp;
    }
    if(X<Z)//ʹX��Ϊ������
    {
        temp = X;
        X = Z;
        Z = temp;
    }
    if(Y<Z)//ʹY>Z
    {
        temp = Y;
        Y = Z;
        Z = temp;
    }

    printf("%3d%3d%3d",X,Y,Z);//��ӡXYZ,��ʱXYZ���Ӵ�С˳�����

    return 0;
}
