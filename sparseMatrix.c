#include<stdio.h>

int main(){
    int m, n;
    int r, c, k = 0;
    int size = 0;
    printf("Enter row and column size for sparse-matrix,\n");
    printf("row-size m : ");
    scanf("%d", &m);
    printf("column-size n : ");
    scanf("%d", &n);

    int sparseMatrix[m][n];
    //Input sparse matrix
    printf("Enter elements for sparse matrix :\n");
    for(r = 0; r < m; r++)
    {
        printf("for row-%d,\n", r+1);
        for(c = 0; c < n; c++){
            scanf("%d", &sparseMatrix[r][c]);
        }
    }

    printf("\nYour sparse-matrix :\n");
    for(r = 0; r < m; r++){
        for(c = 0; c < n; c++){
            printf("\t%d", sparseMatrix[r][c]);
        }
        printf("\n");
    }

    for(r = 0; r < m; r++)
    {
        for(c = 0; c < n; c++){
            if(sparseMatrix[r][c] != 0){
                size++;
            }
        }
    }

    int newMatrix[3][size];

    // New matrix
    for(int r = 0; r < m; r++){
        for(int c = 0; c < n; c++){
            if(sparseMatrix[r][c] != 0)
            {
                newMatrix[0][k] = r+1;
                newMatrix[1][k] = c+1;
                newMatrix[2][k] = sparseMatrix[r][c];
                k++;
            }
        }
    }

    printf("\nNew 3-tuple matrix :\n");
    printf("row\t column\t value\n");
    for(int c = 0; c < size; c++){
        for (int r = 0; r < 3; r++){
            printf(" %d\t", newMatrix[r][c]);
        }
        printf("\n");
    }
    return 0;
}
