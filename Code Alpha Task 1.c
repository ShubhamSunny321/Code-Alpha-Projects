#include<stdio.h>
int main()
{

    int a,b,c;
    int menu;
    printf("\nChoose The Arithmetic Option:-");
    scanf("%d", &menu);
    switch(menu)
    {

    case 1:
        printf("\nEnter The Two Numbers:-");
        scanf("%d%d", &a,&b);
        c = a + b;
        printf("\nThe Addition Of Two Numbers are %d",c);
        break;
    case 2:
        printf("\nEnter The Two Numbers:-");
        scanf("%d%d", &a,&b);
        c = a - b;
        printf("\nThe Subtraction Of Two Numbers are %d",c);
        break;
    case 3:
        printf("\nEnter The Two Numbers:-");
        scanf("%d%d", &a,&b);
        c = a * b;
        printf("\nThe Multiplication Of Two Numbers are %d",c);
        break;
    case 4:
        printf("\nEnter The Two Numbers:-");
        scanf("%d%d", &a,&b);
        c = a / b;
        printf("\nThe Division Of Two Numbers are %d",c);
        break;

        }
        return 0;
}
