#include <stdio.h>

/*Verify whether the expression getchar() != EOF is 0 or 1.*/
int main(){
    int c;
    c = getchar();

    if (c = 1)
	printf("expression \"getchar() != EOF\" = 1\n");
    else
	printf("expression \"getchar() != EOF\" = 0\n");

    return 0;
}
