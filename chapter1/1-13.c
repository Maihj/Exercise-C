#include <stdio.h>

#define MAXLEN 30 /* the maximum length of a word allowed */

/* Print the histogram of the lengths of words in its input. */
int main(){
    int c, i, k;
    int num[100];  /* record the number of characters in every word. */

    i = 0;
    for (k = 0; k < 100; k++)
	num[k] = 0;
    
    while ((c = getchar()) != EOF){
	num[i]++;
	if (c == ' ' || c == '\t' || c == '\n'){
	    /* vertical requirement */
	    for (k = 0; k < MAXLEN - num[i] + 1; k++)
		printf(" ");
	    /* print the length of the word */
	    printf("length: %d", num[i]-1);
	    putchar('\n');
	    i++;
	    continue;
	}
	putchar(c);
    }
    
    return 0;
}
