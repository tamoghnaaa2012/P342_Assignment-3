//Tamoghna Pattanayak,1811168
//Q3
//Program to find the inverse of a matrix and verify that their product is the identity matrix

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int GaussJordan(double matrix[][5],double mat_same[][5],float inv[][5],int size,double max,int p);
int pivot(double matrix[][5],double mat_same[][5],float inv[][5], int size,double max,int p);
int Matrix_mult(double matrix[][5],double mat_same[][5], float inv[][5], int size ,double max,int p);

int main()
{
	int size;
	printf("Enter the size of the matrix(n*n): ");
	scanf("%d", &size);
	int p;
	double max;
	double matrix[5][5];
	FILE* temp1;
	temp1= fopen("mat_q3.txt", "r");
	if (temp1 == NULL)
		exit(1);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fscanf(temp1, "%lf ", &matrix[i][j]);
		}
	}


//Here we are finding Inverse using A=AI equation.
//In A=AI ,we will make the left hand side Identity matrix by row operation....So I have to use two text file containing same matrix..
//so that second file I can use for matrix multiplication...


	double mat_same[5][5];
	FILE* temp2;
	temp2 = fopen("mat_q33.txt", "r");
	if (temp2 == NULL)
		exit(1);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fscanf(temp2, "%lf ", &mat_same[i][j]);
		}
	}

	printf("\nThe matrix A is:\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d   ", (int)(matrix[i][j]));
		}
		printf("\n");
	}

	float inv[5][5];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				inv[i][j] = 1;
			else
				inv[i][j] = 0;
		}
	}

	GaussJordan(matrix,mat_same, inv, size,max,p);
	Matrix_mult(matrix,mat_same, inv, size,max,p);
	return(0);

}

int pivot(double matrix[][5],double mat_same[][5], float inv[][5], int size , double max,int p)
{

	max = matrix[0][0];
    if(matrix[1][0]>=max)
        p=1;
    if(matrix[2][0]>=max)
        p=2;
    for(int j=0;j<=size;j++)
    {
        float temp=matrix[p][j];
        matrix[p][j]=matrix[0][j];
        matrix[0][j]=temp;
    }
    printf("After pivoting \n");

    for(int i=0;i< size;i++)
    {
        for(int j=0;j< size;j++)
        {
            printf("%lf   ", matrix[i][j]);
        }
        printf("\n\n");

    }
}

int GaussJordan(double matrix[][5],double mat_same[][5], float inv[][5], int size,double max,int p)
{
	for (int i = 0; i < size; i++)
	{
		pivot(matrix,mat_same,inv, size , max ,p);
	}

	float c1;
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
		{
			if (i != j)
			{
				c1 = matrix[i][j] / matrix[j][j];

				for (int k = 0; k < size; k++)
				{
					matrix[i][k] = matrix[i][k] - c1 * matrix[j][k];
					inv[i][k] = inv[i][k] - c1 * inv[j][k];
				}
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			inv[i][j] = inv[i][j] / matrix[i][i];
		}
	}

	printf("\nThe inverse of matrix A is:\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d   ", (int)(inv[i][j]));
		}
		printf("\n");
	}
}

int Matrix_mult(double matrix[][5],double mat_same[][5], float inv[][5], int size,double max,int p)
{
	float product[5][5];
	printf("\nThe product of matrix A and its inverse is:\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			product[i][j] = 0;
			for (int k = 0; k < size; k++)
				product[i][j] = product[i][j] + mat_same[i][k] * inv[k][j];
			printf("%d ", (int)(product[i][j]));
		}
		printf("\n");
	}
}







/*
Enter the size of the matrix(n*n): 3

The matrix A is:
1   -3   7
-1   4   -7
-1   3   -6
After pivoting
1.000000   -3.000000   7.000000

-1.000000   4.000000   -7.000000

-1.000000   3.000000   -6.000000

After pivoting
1.000000   -3.000000   7.000000

-1.000000   4.000000   -7.000000

-1.000000   3.000000   -6.000000

After pivoting
1.000000   -3.000000   7.000000

-1.000000   4.000000   -7.000000

-1.000000   3.000000   -6.000000


The inverse of matrix A is:
-3   3   -7
1   1   0
1   0   1

The product of matrix A and its inverse is:
1 0 0
0 1 0
0 0 1

Process returned 0 (0x0)   execution time : 1.564 s

*/
