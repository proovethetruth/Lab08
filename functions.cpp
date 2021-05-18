
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "Lab08.h"

void strcopy(char* a, char* b) {
    for (int i = 0; a[i] != '\0'; i++)
        b[i] = a[i];
}

int search_inside(char* filename, char* word) {
    FILE* fp;
    fp = fopen(filename, "r");
    /*if (!fp)
    {
        printf("\n File not found");
        return -2;
    }*/

    char** str = (char**)calloc(N, sizeof(char*) * N);
    if (!str)
    {
        printf("\n Allocation error");
        return -2;
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
        if (!(str[q] = (char*)calloc(N, sizeof(char) * N)))
        {
            printf("\n Allocation error");
            return -2;
        }
    }

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < N; j++) {
            if (((fscanf(fp, "%c", &str[i][j])) != 1) || str[i][j] == '\n' || str[i][j] == ' ')
                break;
        }
    }

    int i;
    printf("\n Contents of .txt file:\n");
    for (i = 0; str[i] != NULL; i++) {
        printf(" %d) ", i);
        for (int j = 0; j < 20; j++) {
            printf("%c", str[i][j]);
        }
    }

    int mid = 0, flag = 0, a = 0;
    while (a < lines)
    {
        mid = (a + lines) / 2;

        if (flag == mid)
            return -1;
        flag = mid;

        switch (my_strcmp(word, str[mid])) {
        case 0:
            printf("\n CASE 0.");
            return mid;
        case 1:
            printf("\n CASE 1.");
            a = mid;
            break;
        case -1:
            printf("\n CASE -1.");
            lines = mid;
            break;
        }
    }
    free(str);
    return -1;
}

// Чтобы это работало
// Вбил text.txt пробел слово

int my_strcmp(char* a, char* b)
{
    for (; *a && *b && *a == *b; ++a, ++b);
    if (*a < *b)
        return -1;
    return *a > * b;
}