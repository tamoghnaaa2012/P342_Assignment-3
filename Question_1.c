//Program for Gauss Jordan analysis using partial pivoting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define max_size=100

int main()
{
    int var;
	printf("Please enter the number of variables in the equations: ");
	scanf("%d", &var);
	int p;
	double max;
	double matrix[5][5];
	FILE* temp1;
	temp1= fopen("q1.txt", "r");
	if (temp1 == NULL)
		exit(1);

	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var + 1; j++)
		{
			fscanf(temp1, "%lf ", &matrix[i][j]);
		}
	}

	printf("matrixrix representation for given set of equations is:\n ");
	for (int i = 0; i < var; i++)
	{
		for (int j = 0; j < var; j++)
		{
			printf(" %d", (int)(matrix[i][j]));
		}
		printf("   x%d", i + 1);
		printf(" = %lf", matrix[i][var]);
		printf("\n ");
	}

	GaussJordan(matrix, var,max,p);
	return(0);
}





int pivot(double matrix[][5], int var,double max,int p)
{

    max = matrix[0][0];
    if(matrix[1][0]>=max)
        p=1;
    if(matrix[2][0]>=max)
        p=2;
    for(int j=0;j<=var;j++)
    {
        float temp=matrix[p][j];
        matrix[p][j]=matrix[0][j];
        matrix[0][j]=temp;
    }
    printf("After pivoting \n");

    for(int i=0;i< var;i++)
    {
        for(int j=0;j<= var;j++)
        {
            printf("%lf   ", matrix[i][j]);
        }
        printf("\n\n");

    }

}





int GaussJordan(double matrix[][5], int var,double max,int p)

{

	for (int i = 0; i < var; i++)
	{
		pivot(matrix, var,max,p);
	}

	float c, x[20];
	for (int j = 0; j < var; j++)
	{
		for (int i = 0; i < var; i++)
		{
			if (i != j)
			{
				c = matrix[i][j] / matrix[j][j];
				for (int k = 0; k < var + 1; k++)
				{
					matrix[i][k] = matrix[i][k] - c * matrix[j][k];
				}
			}
		}
	}



	printf("\nThe solution is:\n");
	for (int i = 0; i < var; i++)
	{
		x[i] = matrix[i][var] / matrix[i][i];
		printf("\n x%d=%f\n", i + 1, x[i]);
	}
}




/*
Please enter the number of variables in the equations: 3
matrixrix representation for given set of equations is:
  1 3 2   x1 = 2.000000
  2 7 7   x2 = -1.000000
  2 5 2   x3 = 7.000000
 After pivoting
2.000000   5.000000   2.000000   7.000000

2.000000   7.000000   7.000000   -1.000000

1.000000   3.000000   2.000000   2.000000

After pivoting
2.000000   7.000000   7.000000   -1.000000

2.000000   5.000000   2.000000   7.000000

1.000000   3.000000   2.000000   2.000000

After pivoting
2.000000   5.000000   2.000000   7.000000

2.000000   7.000000   7.000000   -1.000000

1.000000   3.000000   2.000000   2.000000


The solution is:

 x1=3.000000

 x2=1.000000

 x3=-2.000000

Process returned 0 (0x0)   execution time : 1.676 s

 */
