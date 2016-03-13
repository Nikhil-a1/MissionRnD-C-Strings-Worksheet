/*
OVERVIEW: Given a inputing, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
#include<stdlib.h>
void reverse(char*, int, int);
void str_words_in_rev(char *input, int len)
{
	int i = 0;
	if (len <= 0 || input == NULL)
		return;
	int start = 0, end = 0;
	while (end <= len)
	{

		if (input[end] == ' ' || input[end] == '\0')
		{
			reverse(input, start, end - 1);
			start = end + 1;
		}
		else if (*input == ' ')
			return;
		end++;
	}
	reverse(input, 0, len - 1);
}
void reverse(char* str, int start, int end)
{
	char temp;
	while (start <= end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

