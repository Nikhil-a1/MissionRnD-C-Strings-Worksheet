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
		int i = 0, j = 0, len = 0,str_len=0,prev_pos=0,count=0,end,start=0;
		int flag = 0;
		char* arr;
		while (str[i]!= '\0')
		{
			i++;
			len++;
		}
		i = 0;
		arr = (char*)malloc(sizeof(char)*len);
		while (str[i] != '\0')
			arr[i++] = str[i++];
		i = 0;
		arr = (char*)realloc(arr, 2 * len);
		end = len;
		str_len = len-1;
		while (str_len>=0)
		{
			if (arr[i] == ' ')
			{
				prev_pos = len;
				len = len + 1;
				while (count > 0)
				{
					if (arr[len] != ' ' || arr[len] != '\0')
					{
						arr[end++] = str[len++];
						count--;
					}
					count = 0;
				}
				while (start < len)
				{
					if (arr[start] == ' ')
					{
						flag = 1;
						arr[end++] = str[start++];
					}
					else if (flag != 0)
						start++;
					else if (flag == 1)
					{
						start++;
						break;
					}
				}
				flag = 0;
			}
			else
			{
				str_len--;
				len--;
				count++;
			}
		}
		arr[j] = '\0';
	}
}