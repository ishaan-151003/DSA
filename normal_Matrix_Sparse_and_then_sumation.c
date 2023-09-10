#include <stdio.h>
int main()
{
    int i, j, m, n, a[10][10], b[10][10], c[10][10];
    int size = 0;
    int size1 = 0;
    printf("Matrix 1:\n");
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter the element in Row %d and column %d: \n", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Matrix 2:\n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter the element in Row %d and column %d: \n", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                size++;
            }
        }
    }
    int sparse[size + 1][3];
    sparse[0][0] = m;
    sparse[0][1] = n;
    sparse[0][2] = size;
    int k = 1;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = a[i][j];
                k++;
            }
        }
    }
    printf("The Sparse Matrix:\n");
    printf("R  C  V\n");
    for (i = 0; i < (size + 1); i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d  ", sparse[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (b[i][j] != 0)
            {
                size1++;
            }
        }
    }
    int sparse1[size1 + 1][3];
    sparse1[0][0] = m;
    sparse1[0][1] = n;
    sparse1[0][2] = size1;
    int e = 1;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (b[i][j] != 0)
            {
                sparse1[e][0] = i;
                sparse1[e][1] = j;
                sparse1[e][2] = b[i][j];
                e++;
            }
        }
    }
    printf("The Sparse Matrix:\n");
    printf("R  C  V\n");
    for (i = 0; i < (size1 + 1); i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d  ", sparse1[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    int size3 = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (c[i][j] != 0)
            {
                size3++;
            }
        }
    }
    int sparse3[size3 + 1][3];
    sparse3[0][0] = m;
    sparse3[0][1] = n;
    sparse3[0][2] = size3;
    int f = 1;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (c[i][j] != 0)
            {
                sparse3[f][0] = i;
                sparse3[f][1] = j;
                sparse3[f][2] = c[i][j];
                f++;
            }
        }
    }
    printf("The sum matrix:\n");
    printf("R  C  V \n");
    for (i = 0; i < (size3 + 1); i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d  ", sparse3[i][j]);
        }
        printf("\n");
    }
    return 0;
}