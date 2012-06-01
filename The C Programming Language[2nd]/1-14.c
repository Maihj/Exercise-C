#include <stdio.h>

/* Print the histogram of the frequencies of different characters in its input. */
int main(){
    int c, i;
    int array[26];
    float num, freq;
    
    num = 0.0;
    for (i = 0; i < 26; i++)
	array[i] = 0;
    
    while ((c = getchar()) != '\n'){
	if (c >= 'A' && c <= 'Z'){
	    ++array[c-'A'];
	    ++num;
	}
	else if (c >= 'a' && c <= 'z'){
	    ++array[c-'a'];
	    ++num;
	}
    }
    /* print the frequencies of every character */
    for (i = 0; i < 26; i++){
	freq = array[i] / num;
	printf("%c   frequency: %.2f\n", (char)(i+65), freq);
    }
    
    return 0;
}
