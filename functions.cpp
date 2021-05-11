
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "Lab08.h"

char** parser() {
    FILE* fp;
    fp = fopen("test.txt", "r");

    char** str = (char**)calloc(20, sizeof(char*) * N);
    if (!str)
    {
        printf("\n Allocation error");
        return NULL;
    }

    char ch;
    int lines = 0;
    while (!feof(fp))
    {
        ch = fgetc(fp);
        if (ch == '\n')
        {
            lines++;
        }
    }
    fseek(fp, 0, SEEK_SET);

    for (int q = 0; q < lines; q++)
    {
        if (!(str[q] = (char*)calloc(20, sizeof(char) * 20)))
        {
            printf("\n Allocation error");
            return NULL;
        }
    }

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < 20; j++) {
            if (((fscanf(fp, "%c", &str[i][j])) != 1) || str[i][j] == '\n' || str[i][j] == ' ')
                break;
        }
    }

    return str;
}

int my_strcmp(char* a, char* b)
{
    for (; *a && *b && *a == *b; ++a, ++b);
    if (*a < *b)
        return -1;
    return *a > * b;
}

int search(char** arr, char* word, int a, int b) {
	int mid = 0;
	while (a < b)
	{
		mid = (a + b) / 2;

		switch (my_strcmp(word, arr[mid])) {
		case 0:
			return mid;
		case 1:
			a = mid;
			break;
		case -1:
			b = mid;
			break;
		}
	}
	return -1;
}