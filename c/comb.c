#include <stdio.h>

int combine (char inString[])
{
	int length;
	char *out;
	length = strlen(inString);
	out = (char *) malloc(length + 1);
	if (!out)
		return 0;
	do_combine (inString, out, length, 0, 0);
	free (out);
	return 1;
}

int do_combine (char in[], char out[], int length, int recurseLevel, int start)
{
	int i;
	for (i = start; i < length; i++) {
		out[recurseLevel] = in[i];
		out[recurseLevel + 1] = '\0';
		printf ("%s\n", out);
		if (i < length - 1) /* recurse if more letters in input */
			do_combine (in, out, length, recurseLevel + 1, i + 1);
	}
}

int main(int argc, const char *argv[])
{
	printf("combining %s\n", argv[1]);
	return combine (argv[1]);
}
