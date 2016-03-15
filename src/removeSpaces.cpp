/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

#include<stdlib.h>

char removeSpaces(char *str) 
{
	if (str==nullptr ||*str=='\0')
	return '\0';
	else
	{
		int i = 0, j = 0;
		char temp;
		while (str[i] != '\0')
		{
			temp = str[i];
			if (temp != ' ')
			{
				str[j] = temp;
				j++;
			}
			i++;
		}
		str[j] = '\0';
	}
}