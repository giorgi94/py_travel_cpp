#include "binomial.h"

double binomial(double n, int k)
{
    if (k < 0)
        return 0.0;
    else if (k == 0)
        return 1.0;
    else if (k == 1)
        return n;

    double result = 1.0;

    for (int i = 0; i < k; i++)
    {
        result *= (n - i) / (i + 1.);
    }

    return result;
}
