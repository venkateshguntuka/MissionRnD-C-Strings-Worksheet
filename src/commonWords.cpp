/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

#include <stdio.h>
#include <malloc.h>

#define SIZE 31
char * split(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			return &str[++i];
		}
		else
			i++;
	}
	return NULL;
}
char ** commonWords(char *str1, char *str2)
{
	if (str1 == NULL&&str2 == NULL)
		return NULL;
	int i = 0;
	char **output = (char **)malloc(10 * sizeof(char *));
	for (char *position1 = str1; position1 != NULL;)
	{
		for (char *position2 = str2; position2 != NULL;)
		{
			int count = 0, flag = 1;
			char *temp1, *temp2;
			temp1 = position1;
			temp2 = position2;
			while (*temp1 != ' ' && *temp2 != ' ')
			{
				if (*temp1 != *temp2)
				{
					flag = 0;
					break;
				}//non common words
				temp1++;
				temp2++;
				count++;
			}
			if (flag == 1 && count >0)
			{
				char *temp;
				temp = position1;
				int j = 0;
				output[i] = (char *)malloc(SIZE * sizeof(char));
				for (j = 0; j<count; j++)
				{
					output[i][j] = *temp;
					temp++;
				}
				output[i][j] = '\0';
				i++;
			}
			position2 = split(position2);
		}
		position1 = split(position1);
	}
	if (i == 0)
		return NULL;
	else
		return output;
}