/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 31
int string_cmp(char*, char*, int, int, char**);
int word_count(char*,char*);
char** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;
	int i = 0, j = 0, len = 0, start = 0, end, m = 0;
	int row = 0, res = 0;
	char* temp;
	char **match;
	len = word_count(str1, str2);
	match = (char**)calloc(sizeof(char*),len);
	for (i = 0; i < len; i++)
		match[i] = (char*)calloc(sizeof(char),SIZE);
	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i + 1] == ' ' || str1[i + 1] == '\0')
		{
			end = i + 1;
			len = end - start;
			temp = (char*)calloc(sizeof(char),(len));
			while (j < len)
				temp[j++] = str1[start++];
			temp[j] = '\0';
			res = string_cmp(temp, str2, len, m, match);
			start = i + 2;
			if (res == 1)
				m++;
			j = 0;
		}
		i++;
	}
	if (m == 0||match=='\0')
		return NULL;
	else
		return match;
}
int string_cmp(char* temp, char* string, int len, int row, char** match)
{
	int count = 0, k = 0, i = 0, l = 0, m = 0, flag = 0;
	while (string[i] != '\0')
	{
		if (string[i] == temp[k] && string[i]!=' ')
		{
			count++;
			flag = 1;
			k++;

		}
		else if (count == len && flag == 1)
			break;
		else
		{
			count = 0;
			flag = 0;
			k = 0;
		}
		i++;
	}
	if (flag == 1 && count == len)
	{
		for (l = 0; l < len; l++)
			match[row][l] = temp[l];
		match[row][l] = '\0';
	}
	else
		flag = 0;
	return flag;
}
int word_count(char* str1, char* str2)
{
	int len1 = 0, len2 = 0, i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == ' ')
			len1++;
			i++;
	}
	i = 0;
	while (str2[i]!='\0')
	{
		if (str2[i] == ' ')
			len2++;
		i++;
	}
	if (len1 < len2)
		return len1;
	else
		return len2;
}