/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void strReverse(char *, int, int);
void str_words_in_rev(char *input, int len){
	int  i, start = 0, count = 0;
	strReverse(input, 0, len - 1);
	for (i = 0; i<=len; i++)
	{
		if (input[i] == ' '||input[i]=='\0')
		{
			strReverse(input, start, i-1);
			start = i + 1;
		}
	}
}

void strReverse(char *str, int start, int end)
{
	char temp;
	while (start<end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}