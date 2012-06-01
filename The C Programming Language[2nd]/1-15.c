#include <stdio.h>

float temperature(float fahr);

/* Print Fahrenheit-Celsius table. */
int main(){
    float fahr, celsius;
    float lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;
    
    printf("fahrenheit celsius\n");
    
    fahr = lower;
    while (fahr <= upper){
	printf(" %.1f %12.1f\n", fahr, temperature(fahr));
	fahr = fahr + step;
    }

    return 0;
}

float temperature(float fahr){
    float celsius;
    celsius = (5.0/9.0) * (fahr - 32.0);
    return celsius;
}
