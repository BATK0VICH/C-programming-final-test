/*
Calculate f(x) with user-defined range and step.
UTM FCIM TI
Dronov Dmitrii
*/
#include <stdio.h>
#include <math.h>

float F(const float x);

int main ()
{
    printf("Enter intervals for x:\nstart: ");
    float start = 0.0;
    scanf("%f", &start);
    
    printf("end: ");
    float end = 0.0;
    scanf("%f", &end);

    //step can't be 0 and also < 0, because it'll never reach the end of the interval.
    float step = 0.0;
    do 
    {
        printf("\nEnter the step: ");
        scanf("%f", &step);
    } while (step <= 0.0);

    for (start; start <= end; start += step)
    {
       printf("F(%.3f) = %.3f\n", start, F(start));
    }
    return 0;
}

float F(const float x) 
{
    if (x <= 0)
    {
        return ((1 + x * x) / (1 + x * x));
    }
    else if (x > 0)
    {
       return (2 * fabs(cos(x)));
    }
}