#include <stdio.h>
#define MAXLINE 1000

int Getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Print the length of arbitrary long input lines. */
int main(){
    int len;  /* current line length */
    int max;  /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    
    max =0;
    while ((len = Getline(line, MAXLINE)) > 0)
	if (len > max){
	    max = len;
	    copy(longest, line);
	}
    if (max > 0)
	printf("The longest input line is: %s\nIt's length is: %d\n", longest, max-1);
    return 0;
}

int Getline(char s[], int lim){
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF
	     && c != '\n'; i++)
	s[i] = c;
    if (c == '\n'){
	s[i] = c;
	i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
	i++;
}
