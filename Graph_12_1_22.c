#include <stdio.h>

int main()
{
    int n, i, j;
    printf("Enter number of Vertices : ");
    scanf("%d", &n);
    int arr[n + 1][n + 1];
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("Is there any edge between %c & %c ? ", 65 + i, 65 + j);
            scanf("%d", &arr[i][j]);
            arr[j][i] = arr[i][j];
        }
    }
    printf("Graph :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}