#include <stdio.h>
#include <math.h>

int main()
{
    double th = 0.005,n,lo=0.0,hi,mid;
    scanf("%lf",&n);
    hi = n;
    while(1)
    {
        mid = (lo+hi)/2;
        if(fabs(n-(mid*mid))<th)
        {
            printf("sqr root: %.2lf\n",mid);
            break;
        }
        else if((mid*mid)<n)
            lo=mid+1;
        else
            hi=mid-1;
    }

    return 0;
}
