#include <stdio.h>

/*Print Celsius-Fahrenheit table*/
int main(){
    float fahr, celsius;
    float lower, upper, step;
    
    lower = -17;
    upper = 148;
    step = 11;
    
    /*Add a heading above the table.*/
    printf("Celsius  Fahrenheit\n");
    
    celsius = lower;
    while (celsius <= upper){
	fahr = (9.0/5.0) * celsius + 32.0;
	printf("%5.1f %11.1f\n", celsius, fahr);
	celsius = celsius + step;
    }

    return 0;
}
