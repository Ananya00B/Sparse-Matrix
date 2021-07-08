#include<stdio.h>

int main()
{
    int ind;
    int i, j;
    int m, n;

    printf("Enter row and column size for Original-Matrix,\n");
    printf("row-size m : ");
    scanf("%d", &m);
    printf("column-size n : ");
    scanf("%d", &n);

    printf("Enter total number of non-zero values in sparse matrix: ");
    scanf("%d", &ind);

    int sparseMatrix[ind][3];
    int transpose[ind][3];
    int total[n], index[n+1], col, loc;

    printf("\nEnter elements of 3-tuple sparse matrix,\n");
    printf("NOTE : row and column index starts with 0.\n\n");
    for(int i = 0; i < ind; i++)
    {
        for (int j = 0; j+2 < 3; j++)
        {
            printf("row, column, value : ");
            scanf("%d%d%d", &sparseMatrix[i][j], &sparseMatrix[i][j+1], &sparseMatrix[i][j+2]);
        }
    }

    //Transpose
    for(i = 0; i < n; i++)
    {
        total[i] = 0;
    }

    for(i = 0; i < ind; i++)
    {
        col = sparseMatrix[i][1];
        total[col] = total[col] + 1;
    }
    index[0] = 0;

    for(i = 1; i <= n; i++)
    {
        index[i] = index[i-1] + total[i-1];
    }

    for(i = 0; i < ind; i++)
    {
        col = sparseMatrix[i][1];
        loc = index[col];
        transpose[loc][0] = sparseMatrix[i][1];
        transpose[loc][1] = sparseMatrix[i][0];
        transpose[loc][2] = sparseMatrix[i][2];
        index[col] = index[col] + 1;
    }

    printf("\nFast-Transpose of sparse matrix :\n");
    printf("\trow\tcolumn\tvalue\n");
    printf("\t%d \t%d \t%d\n", n, m, ind);
    for(int i = 0; i < ind; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("\t%d", transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}
