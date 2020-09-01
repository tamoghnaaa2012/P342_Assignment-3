//In this code we can use any linear equation....




#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int i,j,p,n;
    double a[10][10],b,c,d,x1,x2,x3,temp,max;
    printf("Enter the number of variables in the equation\n");
    scanf("%d",&n);


    printf("Enter the augmented matrix:\n");
    for (i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%lf", &a[i][j]);
        }
    }

    max = a[0][0];
    if(a[1][0]>=max)
        p=1;
    if(a[2][0]>=max)
        p=2;
    for(j=0;j<=n;j++)
    {
        temp=a[p][j];
        a[p][j]=a[0][j];
        a[0][j]=temp;
    }

    printf("After pivoting \n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%lf   ", a[i][j]);
        }
        printf("\n\n");

    }

    b= a[1][0];
    c= a[2][0];
    d= a[0][0];
    for(j=0;j<=i;j++)
    {
        a[1][j]=(a[1][j]-((b/(double)d))*a[0][j]);
        a[2][j]=(a[2][j]-((c/(double)d)*a[0][j]));

    }

    b=a[2][1];
    d=a[1][1];
    for(j=0;j<=n;j++)
    {
        a[2][j]=(a[2][j]-((b/(double)d)*a[1][j]));
    }

    printf("After elimination\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%lf   ", a[i][j]);

        }
        printf("\n\n");
    }
    x3=(a[2][3]/(double)a[2][2]);
    x2=((a[1][3]-(a[1][2]*x3))/(double)a[1][1]);
    x1=((a[0][3]-(a[0][1]*x2)-(a[0][2]*x3))/(double)a[0][0]);
    printf("The solution are:\n");
    printf("x1=%lf\n\n", x1);
    printf("x2=%lf\n\n", x2);
    printf("x3=%lf\n\n", x3);



    return 0;
}




//Here I have solved only question 1 but we can use any linear equation.....


/*
Enter the number of variables in the equation
3
Enter the augmented matrix:
a[0][0] = 1
a[0][1] = 3
a[0][2] = 2
a[0][3] = 2
a[1][0] = 2
a[1][1] = 7
a[1][2] = 7
a[1][3] = -1
a[2][0] = 2
a[2][1] = 5
a[2][2] = 2
a[2][3] = 7
After pivoting
2.000000   5.000000   2.000000   7.000000

2.000000   7.000000   7.000000   -1.000000

1.000000   3.000000   2.000000   2.000000

After elimination
2.000000   5.000000   2.000000   7.000000

0.000000   2.000000   5.000000   -8.000000

0.000000   0.000000   -0.250000   0.500000

0.000000   0.000000   0.000000   0.000000

The solution are:
x1=3.000000

x2=1.000000

x3=-2.000000


Process returned 0 (0x0)   execution time : 2.402 s

*/
