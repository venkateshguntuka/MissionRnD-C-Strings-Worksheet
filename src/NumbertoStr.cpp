/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
int convertToString(char *str, float number, int i);
void mystrReverse(char *str, int start, int end);
int power(int x, unsigned int y);
void number_to_str(float number, char *str, int afterdecimal)
{
	int i = 0;
	if (number<0)
	{
		str[i++] = '-';
		number = 0 - number;
	}
	int j = convertToString(str, number, i);
	mystrReverse(str, i, j - 1);
	if (afterdecimal>0)
		str[j++] = '.';
	int floatstart = j;
	float res = number - (int)number;
	float result = res *power(10, afterdecimal);
	j = convertToString(str, result, j);
	mystrReverse(str, floatstart, j - 1);
	str[j] = '\0';
}
int convertToString(char *str, float number, int i)
{
	int num = (int)number;
	while (num != 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	return i;
}
void mystrReverse(char *str, int start, int end)
{
	int i, j = end - start;
	for (i = 0; i<j; i++)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
int power(int x, unsigned int y)
{
	if (y == 0)
		return 1;
	int i, res = 1;
	for (i = 0; i<y; i++)
		res *= x;
	return res;

}
