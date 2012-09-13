#include <stdio.h>

/* Copy input to output, replacing each tab by \t, each backspace by \b, each backslash by \\. */
int main(){
    int c;

    while ((c = getchar()) != EOF){
	if (c == '\t')
	    printf("\\t");
	else if (c == '\b')
	    printf("\\b");
	else if (c == '\\')
	    printf("\\\\");
	else
	    putchar(c);
    }
    
    return 0;
}
