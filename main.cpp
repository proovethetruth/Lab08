
#define _CRT_SECURE_NO_WARNINGS
// Написать функцию двоичного поиска в упорядоченном массиве слов.

#include <stdio.h>
#include <stdlib.h>
#include "Lab08.h"

int main() {
	int amount = 5;

	char** str = (char**)malloc(amount * sizeof(char));

	if (str == NULL) {
		printf("\n Error allocating memory!");
		return -101;
	}

	for (int i = 0, j = 0; i < amount; i++)
	{
		str[i] = (char*)malloc(15 * sizeof(int));

		if (str[i] == NULL) {
			printf("\n Error allocating memory!");
			return -101;
		}

		printf("\n Enter array element #%d: ", i + 1);
		fgets(str[i], 15, stdin);
	}

	// "ant", "apple", "business", "butcher", "donkey", "forest"
	// "garage", "lolipop", "orange", "zoo"

	int a = 0;
	int b = amount - 1;

	printf("\n Input word: ");
	char* word = (char*)malloc(15 * sizeof(char));								// word input
	fgets(word, 15, stdin);
	
	int match = search(str, word, a, b);
	printf("\n Succesfully found matching word on index: %d", match);

	return 0;
}