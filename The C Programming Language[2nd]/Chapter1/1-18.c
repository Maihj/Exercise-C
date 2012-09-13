#include <stdio.h>

/* Remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. */
int main(){
    int c;
    
    while ((c = getchar()) != EOF){
	if (c != ' ' && c != '\t')
	    putchar(c);
    }

    return 0;
}
