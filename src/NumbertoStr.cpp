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
int power(float, int);
void num_reverse(char*, int, int);
int num_to_string(char*, int, int);

void number_to_str(float number, char *str,int afterdecimal)
{
	int pos = 0, rem, num;
	int num2, point_pos = 0, start = 0;
	char  flag = 0, negative = 0;
	if (number < 0)
	{
		str[start++] = '-';
		number = -1 * number;
		negative = 1;
	}
	num = number;
	if (num<number)
		flag = 1;
	pos = start;
	number = number - num;//0.341
	pos = num_to_string(str, num, pos);
	num_reverse(str, start, pos);
	if (flag == 1)
	{
		str[pos] = '.';
		point_pos = pos;
		pos++;
		num2 = power(number, afterdecimal);
		pos = num_to_string(str, num2, pos);
		num_reverse(str, point_pos + 1, pos);
	}
	str[pos] = '\0';
}
int num_to_string(char* str, int num, int pos)
{
	int rem;
	while (num != 0)
	{
		rem = num % 10;
		str[pos] = rem + '0';
		num = num / 10;
		pos++;
	}
	return pos;
}
int power(float num, int afterdecimal)
{
	if (afterdecimal > 0)
	{
		while (afterdecimal>0)
		{
			num = num * 10;
			afterdecimal--;
		}
		return num;
	}
	else
		return 0;
}
void num_reverse(char* str, int i, int len)
{
	int j = len - 1;
	char temp;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
