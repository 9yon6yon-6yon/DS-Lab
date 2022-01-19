#include <stdio.h>

void dfs(int g[100][100], int visited[], int source, int n);

int main()
{
    int vertex,i,j;

    printf("enter number of vertex:");
    scanf("%d", &vertex);
    int arr[100][100], visited[100];

    for (i=0; i<vertex; i++)
    {
        for (j=i+1; j<vertex; j++)
        {
            printf("edge between %c & %c: ", 65+i, 65+j);
            scanf("%d",&arr[i][j]);
            arr[j][i] = arr[i][j];
        }

    }

    printf("graph values: \n");

    for(i=0; i<vertex; i++)
    {
        for(j=0; j<vertex; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    dfs(arr, visited, 3, vertex);
    return 0;
}

void dfs(int g[][100], int visited[], int source, int n)//n: number of vertices, k: node
{
    int i;
    visited[source] = 1;
    printf("%c visited\n",65+source);
    for(i = 0; i< n; i++)
    {
        if(g[source][i] == 1 && visited[i] == 0)
            dfs(g, visited, i, n);
    }
}
