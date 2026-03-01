#include <stdio.h>
void displayMatrix(int matrix[10][10], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}
void addMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int row, int col )
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
           result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
void multiplyMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int row1, int col1, int row2, int col2 )
{
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col2; j++)
        {
           result[i][j] = 0;
            for(int k = 0; k < col1; k++)
            {
            result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
void transposeMatrix(int matrix[10][10], int result[10][10], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
           result[j][i] = matrix[i][j];
        }
    }
}
int main()
{
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int row1, col1, row2, col2;
    printf("Enter rows and columns for matrix 1:");
    scanf("%d%d", &row1, &col1);
    printf("Element of matrix 1:\n");
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col1; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter rows and columns for matrix 2:");
    scanf("%d%d", &row2, &col2);
    printf("Element of matrix 2:\n");
    for(int i = 0; i < row2; i++)
    {
        for(int j = 0; j < col2; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("Matrix 1:\n");
    displayMatrix(matrix1, row1, col1);
    printf("Matrix 2:\n");
    displayMatrix(matrix2, row2, col2);
    if(row1 == row2 && col1 == col2)
    {
        addMatrices(matrix1, matrix2, result, row1, col1);
        printf("Sum of matrices:\n");
        displayMatrix(result, row1, col1);
    }
    else
    {
        printf("Matrices can not be added.\n");
    }
    if(col1 == row2)
    {
        multiplyMatrices(matrix1, matrix2, result, row1, col1, row2, col2);
        printf("Product of matrices:\n");
        displayMatrix(result, row1, col2);
    }
    else
    {
        printf("Matrices can not be multiplied.\n");
    }
    transposeMatrix(matrix1, result, row1, col1);
    printf("Transpose of matrix 1:\n");
    displayMatrix(result, col1, row1);
 return 0;
}
