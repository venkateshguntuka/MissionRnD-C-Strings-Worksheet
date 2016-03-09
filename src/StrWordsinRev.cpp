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

	int i = 0, j = 0, start = 0;
	strReverse(input, start, len);
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '\0' || input[i] == ' ')
		{
			j = i - 1;
			strReverse(input, start, j);
			start = i + 1;
		}
	}
}
void strReverse(char *input, int strt, int endstr)
{

	char temp;
	int i = strt, j = endstr;
	while (i < j)
	{
		temp = input[j];
		input[j] = input[i];
		input[i] = temp;
		i++;
		j--;
	}
}
