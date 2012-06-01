#include <stdio.h>

#define BLANK    1    /* already have ' ' before ' ' */
#define NOBLANK  0    /* no ' ' before ' ' */

/* Copy input to output, replacing one or more blanks by a single blank. */
int main(){
    int c, state;
    state = NOBLANK;
    
    while ((c = getchar()) != EOF){
	if (c == ' ' && state == NOBLANK){
	    state = BLANK;
	    putchar(c);
	}
	else if (c == ' ' && state == BLANK)
	    continue;
	else if (c != ' ' && state == BLANK){
	    state = NOBLANK;
	    putchar(c);
	}
	else 
	    putchar(c);	
    }

    return 0;
}
