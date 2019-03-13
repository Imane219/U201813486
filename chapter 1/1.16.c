/*输入三个整数XYZ，在XYZ输出时按从大到小排列


参数说明：XYZ —— 存放三个整数
         temp —— 在交换XYZ值时起保存值的作用

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X,Y,Z,temp;
    scanf("%d%d%d",&X,&Y,&Z);//输入XYZ
    if(X<Y)//使X>Y
    {
        temp = X;
        X = Y;
        Y = temp;
    }
    if(X<Z)//使X成为最大的数
    {
        temp = X;
        X = Z;
        Z = temp;
    }
    if(Y<Z)//使Y>Z
    {
        temp = Y;
        Y = Z;
        Z = temp;
    }

    printf("%3d%3d%3d",X,Y,Z);//打印XYZ,此时XYZ按从大到小顺序输出

    return 0;
}
