#include <stdio.h>

/*Print Fahrenheit-Celsius table*/
int main(){
    float fahr, celsius;
    float lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;
    
    /*Add a heading above the table.*/
    printf("Fahrenheit  Celsius\n");
    
    fahr = lower;
    while (fahr <= upper){
	celsius = (5.0/9.0) * (fahr-32.0);
	printf("%5.0f %13.1f\n", fahr, celsius);
	fahr = fahr + step;
    }

    return 0;
}
