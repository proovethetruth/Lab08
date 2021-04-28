
#include <string.h>
#include "Lab08.h"

int search(char** arr, char* word, int a, int b) {
	int mid = 0;
	while (a <= b)
	{
		mid = (a + b) / 2;
		switch (strcmp(word, arr[mid])) {
		case 0:
			return mid + 1;
		case 1:
			a = mid + 1;
			break;
		case -1:
			b = mid - 1;
			break;
		}
	}
	return -1;
}