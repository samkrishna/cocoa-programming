#include <stdio.h>
#include <math.h>

int main (int argc, const char * argv[])
{
    int         nScanned;
    int         n;
    double      sumX, sumY;
    double      sumX2, sumY2;
    double      sumXY;
    
    n = 0;
    sumXY = sumY = sumX2 = sumY2 = sumXY = 0.0;
    
    do {
        double  x, y;
        int     nScanned = scanf("%lg %lg", &x, &y);
        if (nScanned == 2) {
            n++;
            sumX += x;
            sumX2 += x * x;
            sumY += y;
            sumY2 += y * y;
            sumXY += x * y;
        }
    } while (nScanned == 2);
    double       slope,   intercept;
    slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    intercept = (sumY - slope * sumX) / n;
    
    double      correlation;
    correlation = slope * sqrt((n * sumX2 - sumX * sumX)
                               / (n * sumY2 - sumY * sumY));
    printf ("%g\t%g\t%g\n",   slope,   intercept,   correlation);
    return   0;
}
