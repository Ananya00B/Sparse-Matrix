#include<stdio.h>

int main()
{
    int ind;
    int i, j, k = 0;
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

    printf("\nEnter elements for 3-tuple sparse matrix,\n");
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
        for(j = 0; j < ind; j++)
        {
            if(sparseMatrix[j][1] == i)
            {
                transpose[k][0] = sparseMatrix[j][1];
                transpose[k][1] = sparseMatrix[j][0];
                transpose[k][2] = sparseMatrix[j][2];
                k++;
            }
        }
    }

    printf("\nTranspose of sparse matrix :\n");
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
