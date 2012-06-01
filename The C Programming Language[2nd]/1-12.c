#include <stdio.h>

/* Print the input one word per line. */
int main(){
    int c;
    
    while((c = getchar()) != EOF){
	if (c == ' ' || c == '\n' || c == '\t'){
	    putchar('\n');
	    continue;
	}
	putchar(c);
    }

    return 0;
}
