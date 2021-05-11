
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
	char* word = (char*)malloc(sizeof(char) * 20);								// word input
	fgets(word, 20, stdin);

	int match = search(str, word, a, b);
	printf(" Succesfully found matching word on index: %d\n", match);

	return 0;
}