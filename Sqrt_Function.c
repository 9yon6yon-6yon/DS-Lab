#include <stdio.h>
#include <math.h>

int SqrtFunction(int n)//squre function
{
    int low = 0, high = n;
    if (n < 2)
        return n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid * mid) == n)
            return mid;
        else if ((mid * mid) > n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return fabs(high);
}
void print_sqrtFunction(double n)//squre function using bst(Binary search tree)
{
    double low = 0, high = n;

    if (n < 2)
        printf("n is %.2lf\n", n);

    while (low <= high)
    {
        double mid = (low + high) / 2;
        printf("Low %.2lf\tHigh %.2lf\t", fabs(low), fabs(high));
        printf("Mid %2.lf\n", mid);
        if ((mid * mid) == n)
        {
            printf("Mid %2.lf\t ", mid);
            break;
        }
        else if ((mid * mid) > n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("\nSqrt = %.2lf \n", high);
    return;
}
int main()
{
    int n;
    printf("Enter value : ");
    scanf("%d", &n);
    print_sqrtFunction(n);
    printf("\nSqure root of %d is : %d\n", n, SqrtFunction(n));

    return 0;
}