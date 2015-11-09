/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int length(char *s)
{
	int i = 0;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}
int isValid(char *s)
{
	int d, i, m, y, month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, leap = 0;
	if (length(s) != 10)return 0;
	for (i = 0; i<10; i++)
	{
		if (i == 2 || i == 5)continue;
		if ((s[i] - 48)<0 || (s[i] - 48)>9)return 0;
	}
	if (s[2] != '-' || s[5] != '-')
		return 0;
	d = (s[0] - 48) * 10 + (s[1] - 48);
	m = (s[3] - 48) * 10 + (s[4] - 48);
	y = ((s[6] - 48) * 1000) + ((s[7] - 48) * 100) + ((s[8] - 48) * 10) + ((s[9] - 48));
	if (y == 0)return 0;
	if (y % 4 == 0)leap = 1;
	if ((y % 100 == 0) && (y % 400 != 0))leap = 0;
	if (d <= 0 || d>31)return 0;
	if (m <= 0 || m>12)return 0;
	if (m == 2 && d > 29)return 0;
	if (m == 2 && leap == 1 && d <= 29)return 1;
	if (month[m - 1] < d)return 0;
	return 1;
}
int isOlder(char *dob1, char *dob2) {
	int d1, d2, m1, m2, y1, y2;
	if (isValid(dob1) == 0 || isValid(dob2) == 0)return -1;
	d1 = (dob1[0] - 48) * 10 + (dob1[1] - 48);
	m1 = (dob1[3] - 48) * 10 + (dob1[4] - 48);
	y1 = ((dob1[6] - 48) * 1000) + ((dob1[7] - 48) * 100) + ((dob1[8] - 48) * 10) + ((dob1[9] - 48));
	d2 = (dob2[0] - 48) * 10 + (dob2[1] - 48);
	m2 = (dob2[3] - 48) * 10 + (dob2[4] - 48);
	y2 = ((dob2[6] - 48) * 1000) + ((dob2[7] - 48) * 100) + ((dob2[8] - 48) * 10) + ((dob2[9] - 48));
	if (y1 < y2)return 1;
	else if (y1>y2)return 2;
	else if (y1 == y2)
	{
		if (m1 < m2)return 1;
		else if (m1>m2)return 2;
		else if (m1 == m2)
		{
			if (d1 < d2)return 1;
			else if (d1>d2)return 2;
			else if (d1 == d2)return 0;
		}
	}
}
