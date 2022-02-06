#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection_sort(int data[],int n);
void bubble_sort(int data[],int n);

int main()
{
    //printf("hello");
    int data[100], i, j, n;
    printf("enter array size: ");
    scanf("%d",&n);

    srand(time(NULL));
    for(i=0; i<n; i++)
    {
        //scanf("%d",&data[i]);
        data[i] = (rand()%100) + 1;
    }

    printf("before sorting\n");
    for(i=0; i<n; i++)
        printf("%d ",data[i]);

    //selection_sort(data,n);
    bubble_sort(data,n);

    printf("\n\nafter sorting\n");
    for(i=0; i<n; i++)
        printf("%d ",data[i]);
    return 0;
}

void selection_sort(int data[],int n)
{
    int i,j,min_index,temp;

    for(i=0; i<n; i++)
    {
        min_index=i;
        for(j=i;j<n;j++)
        {
            if(data[min_index] > data[j])
                min_index = j;
        }
        if(min_index != i)
        {
            temp = data[min_index];
            data[min_index] = data[i];
            data[i] = temp;
        }

    }

}

void bubble_sort(int data[],int n)//bubble sort
{
    int i,j,temp,flag;
    for(i=0; i<n; i++)
    {
        flag = 1;
        for(j=0;j<n-1-i;j++)
        {
            if(data[j] > data[j+1])
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
                flag = 0;
            }
        }
        if(flag == 1) break;
    }
    printf("\nvalue of i in bubble sort: %d\n",i);
}