#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct
{
    char *key;
    int value;
} dict;

// sorting fucntions
void sort(void *a, size_t structSize, size_t numSize, int (*compare)(void *x, void *y))
{
    size_t len = structSize / numSize;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (compare(a + numSize * j, a + numSize * (j + 1)) > 0)
            {
                char temp[numSize];
                memcpy(temp, a + numSize * j, numSize);
                memcpy(a + numSize * j, a + numSize * (j + 1), numSize);
                memcpy(a + numSize * (j + 1), temp, numSize);
            }
        }
    }
}

int compare_float(void *x, void *y)
{
    float *v1 = (float *)x;
    float *v2 = (float *)y;
    if (*v1 > *v2)
    {
        return 1;
    }
    return 0;
}

int compare_key(dict *x, dict *y)
{
    char *v1 = (dict *)x->key;
    char *v2 = (dict *)y->key;
    return strcmp(v1, v2);
}

int compare_value(dict *x, dict *y)
{
    int v1 = (dict *)x->value;
    int v2 = (dict *)y->value;
    char *l1 = (dict *)x->key;
    char *l2 = (dict *)y->key;
    if (v1 != v2)
    {
        if (v1 < v2)
        {
            return 1;
        }
        return 0;
    }
    else
    {
        return strcmp(l1, l2);
    }
}
int main()
{
    float numbers[] = {645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25};
    dict people[] =
        {
            {"Hal", 20},
            {"Susann", 31},
            {"Dwight", 19},
            {"Kassandra", 21},
            {"Lawrence", 25},
            {"Cindy", 22},
            {"Cory", 27},
            {"Mac", 19},
            {"Romana", 27},
            {"Doretha", 32},
            {"Danna", 20},
            {"Zara", 23},
            {"Rosalyn", 26},
            {"Risa", 24},
            {"Benny", 28},
            {"Juan", 33},
            {"Natalie", 25}};

    // sort list of numbers
    sort(numbers, sizeof(numbers), sizeof(float), compare_float);
    for (int i = 0; i < (sizeof(numbers) / sizeof(float)); i++)
    {
        printf("%0.2f ", numbers[i]);
    }
    printf("\n\n");

    // sort by key
    sort(people, sizeof(people), sizeof(dict), compare_key);
    for (int i = 0; i < (sizeof(people) / sizeof(dict)); i++)
    {
        printf("{%s : %d},\n", people[i].key, people[i].value);
    }
    printf("\n");

    // sort by value
    sort(people, sizeof(people), sizeof(dict), compare_value);
    for (int i = 0; i < (sizeof(people) / sizeof(dict)); i++)
    {
        printf("{%s : %d},\n", people[i].key, people[i].value);
    }
    printf("\n");
    return 0;
}
