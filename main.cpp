
#define _CRT_SECURE_NO_WARNINGS
// Написать функцию двоичного поиска в упорядоченном массиве слов.

#include <stdio.h>
#include <stdlib.h>
#include "Lab08.h"

int main(int argc, char* argv[]) {
	char* filename = (char*)malloc(sizeof(char) * N);
	char* word = (char*)malloc(sizeof(char) * N);

	strcopy(argv[1], filename);
	strcopy(argv[2], word);

	printf("%s", filename);
	printf("%s", word);
	/*printf("\n\n Input filename and word: ");
	if (scanf("%s %s", filename, word) != 2)
	{
		printf(" Input error\n");
		return -2;
	}*/
	if (!word || !filename)
	{
		printf("\n Allocation error");
		return -2;
	}

	if (word[0] > 47 && word[0] < 58)
	{
		printf(" Input error\n");
		return -2;
	}

	int i = 0;
	for (; word[i] != '\0'; i++);
		word[i] = '\n';
	word[i+1] = '\0';
	
	int match = search_inside(filename, word);

	if (match >= 0)
		printf(" Succesfully found matching word on index: %d\n", match);
	else
		printf(" No matches found");

	return 0;
}