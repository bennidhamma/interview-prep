#include <stdio.h>
#include <math.h>

char get_char (int digit, int num)
{
	digit -= 2;
	digit *= 3;
	digit += num % 3;
	return 'A' + digit;
}

void numwords (int num, int level, char *out)
{
	if (level == 10) {
		printf("%s\n", out);
		return;
	}
	int i, d;
	int power;
	if (level == 0)
		d = num / 1000000000;
	else {	
		power = pow (10, 10 - level);
		d = num % power / (power/10);
	}
	if (d == 1) {
		out[level] = '1';
		numwords (num, level + 1, out);
	}
	else if (d == 0) {
		out[level] = '0';
		numwords (num, level + 1, out);
	}
	else {
		for (i = 0; i < 3; i++)
		{
			out[level] = get_char(d, i);
			numwords (num, level + 1, out);
		}
	}
}

#define N 7

void numwords_iter (int digits[])
{
	int exp, i, j, d, combinations;
	char *out = malloc(N+1);
	for (i = 0; i < N; i++)
		out[i] = '-';
	out[N] = '\0';
	exp = 0;
	for (i = 0; i < N; i++)
		if (digits[i] == 0)
			out[i] = '0';
		else if (digits[i] == 1)
			out[i] = '1';
		else
			exp++;
	combinations = pow(3,exp);
	for (i = 0; i < combinations; i++) {
		d = 0;
		for (j = 1; j <= exp; j++) {
			while (digits[d] <= 1) d++;
			out[d] = get_char(digits[d++], (int)(i / pow (3, exp - j)) % 3);
		}
		printf("%s\n", out);
	}
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int digits[N];
	for (i = 0; i < N; i++)
		digits[i] = argv[1][i] - '0';
	numwords_iter(digits);
	return;

	int num = atoi (argv[1]);
	char out[11];
	out[10] = '\0';
	numwords (num, 0, &out);	
	return 0;
}
