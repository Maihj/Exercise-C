#include <stdio.h>
#define MAXLINE 1000

int Getline(char line[], int maxline);

/* Print all input lines that are longer than 80 characters. */
int main(){
    int len;
    char line[MAXLINE];
    
    while (1){
	if ((len = Getline(line, MAXLINE)) > 80)
	    printf("%sLength: %d\n", line, len-1);
    }
    
    return 0;
}

int Getline(char line[], int maxline){
    int c, i;
    
    for (i = 0; i < maxline-1 && (c = getchar()) != EOF 
	     && c != '\n'; i++)
	line[i] = c;
    if (c == '\n'){
	line[i] = c;
	i++;
    }
    line[i] = '\0';
    return i;
}
