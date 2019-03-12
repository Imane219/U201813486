#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X,Y,Z,temp;
    scanf("%d%d%d",&X,&Y,&Z);
    if(X<Y)
    {
        temp = X;
        X = Y;
        Y = temp;
    }
    if(X<Z)
    {
        temp = X;
        X = Z;
        Z = temp;
    }
    if(Y<Z)
    {
        temp = Y;
        Y = Z;
        Z = temp;
    }

    printf("%3d%3d%3d",X,Y,Z);

    return 0;
}
