#include <stdio.h>

#define MAXLINE 100

/* Read a line into s, return its length. */
int Getline(char s[], int maxline);
/* Reverse the character string s with length len. */
void reverse(char s[], int len);

/* Reverse every input a line at a time. */
int main(){
    int len, i;            /* the length of every input line */;
    
    char line[MAXLINE]; /* the input line */
    
    while ((len = Getline(line, MAXLINE)) > 0){
	reverse(line, len);
	printf("%s\n", line);
	for (i = 0; i < len; i++)
	    line[i] = 0;
    }

    return 0;
}

int Getline(char s[], int maxline){
    int c, i;
    for (i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
	s[i] = c;

    return i;
}

void reverse(char s[], int len){
    int i, temp;
    
    if (len % 2 == 0){
	for (i = 0; i < len/2; i++){
	    temp = s[i];
	    s[i] = s[len-i-1];
	    s[len-i-1] = temp;
	}
    }
    else {
	for (i = 0; i < (len-1)/2; i++){
	    temp = s[i];
	    s[i] = s[len-i-1];
	    s[len-i-1] = temp;
	}
    }
}
