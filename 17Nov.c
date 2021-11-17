#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void linearSearch(int data[], int n, int key);
void binarySearch(int data[], int n, int key);
void insertion_sort(int data[],int n);

int main()
{
    int data[100000], i, j, n, key;
    printf("%d\n", sizeof(int));
    printf("enter array size: ");
    scanf("%d",&n);

    srand(time(NULL));
    for(i=0; i<n; i++)
    {
        //scanf("%d",&data[i]);
        data[i] = (rand()%100) + 1;
    }

//    printf("data: ");
//    for(i=0; i<n; i++)
//        printf("%d ",data[i]);

    printf("\n\nenter search value: ");
    scanf("%d",&key);

    //insertion_sort(data,n);

//    int index = linearSearch(data, n, key);
//    if(index != -1) printf("found in index %d\n",index);
//    else printf("not found\n");


    time_t startTime = clock();
    linearSearch(data, n, key);

    //binarySearch(data, n, key);
    time_t endTime = clock();

    double reqTime = (double)(endTime - startTime)/CLOCKS_PER_SEC;

    printf("time required: %lf\n", reqTime);

    return 0;
}


void linearSearch(int data[], int n, int key)
{
    int i, flag = 0;
    for(i=0; i<n; i++)
    {
        if(data[i] == key)
        {
            printf("found in index %d\n",i);
            flag = 1;
        }
    }
    if(flag == 0)
        printf("not found\n");

    return;

}

void binarySearch(int data[], int n, int key)
{
    int lo = 0, hi = n-1, mid;


    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(data[mid] == key)
        {
            printf("found\n");
            return;
        }
        else if(data[mid] > key) hi = mid - 1;
        else lo = mid + 1;

    }
    printf("not found\n");
    return;

}

void insertion_sort(int data[],int n)
{
    int i,j,temp,key;
    for(i = 1; i<n; i++)
    {
        key = data[i];
        j = i-1;
        while(j >= 0 && data[j] > key)
        {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }
}






