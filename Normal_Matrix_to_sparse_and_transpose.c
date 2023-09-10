#include <stdio.h>
int main()
{
    int i, j, m, n, a[10][10], transpose[10][10], size = 0;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter the element in Row %d and column %d:\n", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            transpose[j][i] = a[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (transpose[i][j] != 0)
            {
                size++;
            }
        }
    }
    int sparse[size + 1][3];
    sparse[0][0] = n;
    sparse[0][1] = m;
    sparse[0][2] = size;
    int k = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (transpose[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = transpose[i][j];
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
    return 0;
}