#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection_Sort(int data[],int n)
{
    int i,j,min_index,temp;
    for(i=0; i<n; i++)
    {
        min_index =i;
        for(j=i; j<n; j++)
        {
            if(data[min_index]>data[j])
            {
                min_index=j;
            }

        }
        if(min_index!= i)
        {
            temp = data[min_index];
            data[min_index] = data [i];
            data[i] = temp;
        }
    }

}
void insertion_Sort(int data[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = data[i];
        j = i - 1;

        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int array[50];
    srand(time(NULL));

    printf("Before Sorting\n");
    for(i=0; i<n; i++)
        array[i]=(rand()%100)+1;
    for(i=0; i<n; i++)
        printf("%d,",array[i]);

    // selection_Sort(array,n);
    insertion_Sort(array,n);
    printf("\n\nAfter sorting\n");
    for(i=0; i<n; i++)
        printf("%d,",array[i]);



printf("\n\nA \n");





    //  int arr[n];
    // for(int i =0; i<n; i++)
    // {
    //   scanf("%d",&arr[i]);
    // }
    // for(int i=0; i<n; i++)
    // {
    //  printf("%d ",arr[i]);
    //   if(max<arr[i])
    //        max= arr[i];
    //   if(min>arr[i])
    //        min = arr[i];
    //}
    // int max = arr[0];
    // int min = arr[0];
    //  printf("\nMax = %d \nMin = %d",max,min);



    return 0;
}
