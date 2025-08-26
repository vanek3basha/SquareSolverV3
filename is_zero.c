#include "is_zero.h"
#include <stdlib.h>
#include <math.h>
int is_zero(double x)
{
    double epsilon = 0.00001;

    if(fabs(x) < epsilon)
        return 1;
    return 0;
}