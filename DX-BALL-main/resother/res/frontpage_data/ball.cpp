#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    // if(n==5000)
    // printf("Dipto\n");
    // else if(n==2000)
    // printf("Lina\n");
    // else printf("DipLin\n");
    switch (n)
    {
        case 5000:
            printf("Dipto\n");
            break;
        case 2000:
            printf("Lina\n");
            break;
        default:
            printf("DipLin\n");
            break;
    }
    return 0;
}