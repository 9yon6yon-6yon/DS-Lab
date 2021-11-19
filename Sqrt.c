#include <stdio.h>

double sqrtFunction(double n)
{
    double low = 0, high = n;
    if (n < 2)
        return n;

    while (low <= high)
    {
        double mid = (low + high) / 2;
        if ((mid * mid) == n)
            return mid;
        else if ((mid * mid) > n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return high;
}
void print_sqrtFunction(double n)
{
    double low = 0, high = n;

    if (n < 2)
        printf("n is %.2lf", n);

    while (low <= high)
    {
       double mid = (low + high) / 2;
        printf("Low %.2lf\tHigh %.2lf\t", low, high);
        printf("\tMid %2.lf\n", mid);
        if ((mid * mid) == n)
        {
            printf("\tMid %2.lf\t ", mid);
            break;
        }
        else if ((mid * mid) > n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("\nHigh = %.2lf \n",high);
    return;
}
int main()
{
    double n;
    printf("Enter value : ");
    scanf("%lf", &n);
    print_sqrtFunction(n);
    printf("Squre root of %.0lf is : %.2lf\n", n, sqrtFunction(n));

    return 0;
}