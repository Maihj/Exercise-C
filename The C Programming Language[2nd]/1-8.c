#include <stdio.h>

/*Count blanks, tabs, and newlines.*/
int main(){
    int c, nblanks, ntabs, nlines;
    nblanks = ntabs = nlines = 0;
    
    while ((c = getchar()) != EOF){
	if (c == ' ')
	    nblanks++;
	else if (c == '\t')
	    ntabs++;
	else if (c == '\n')
	    nlines++;
    }

    printf("The number of blanks is %d\n", nblanks);
    printf("The number of tabs is %d\n", ntabs);
    printf("The number of newlines is %d\n", nlines);
    
    return 0;
}
