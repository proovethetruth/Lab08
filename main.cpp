
#define _CRT_SECURE_NO_WARNINGS
// Написать функцию двоичного поиска в упорядоченном массиве слов.

#include <stdio.h>
#include <stdlib.h>
#include "Lab08.h"

int main() {
	char** str = parser();
	
	int i;
	printf("\n Contents of .txt file:\n");
	for (i = 0; str[i] != NULL; i++) {
		printf("\t%d) ", i);
		for (int j = 0; j < 20; j++) {
			printf("%c", str[i][j]);
		}
	}

	int a = 0;
	int b = i;

	printf("\n\n Input word: ");
	char* word = (char*)malloc(sizeof(char) * N);						// word input
	if (!word)
	{
		printf("\n Allocation error");
		return -2;
	}

	fgets(word, N, stdin);
	if (word[0] > 47 && word[0] < 58)
	{
		printf(" Input error\n");
		return -2;
	}

	int match = search(str, word, a, b);

	if (match != -1)
		printf(" Succesfully found matching word on index: %d\n", match);
	else
		printf(" No matches found");

	return 0;
}