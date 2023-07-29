/*
** EPITECH PROJECT, 2023
** strdup
** File description:
** strdup
*/

#include "my.h"

char * my_strdup ( char const * src)
{
    char *str;
    int i = 0;
    int s = my_strlen(src);
    str = malloc(sizeof(char) * (s + 1));
    if (str == NULL)
        return NULL;
    while (i != s) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *my_strdup_path(char const *src1, char const *src2, char delimiter)
{
    char *str;
    int i = 0;
    int j = 0;
    int length = my_strlen(src1) + my_strlen(src2) + 1;
    str = malloc(sizeof(char) * (length + 1));
    if (str == NULL)
        return NULL;
    while (i != my_strlen(src1)) {
        str[i] = src1[i];
        i++;
    }
    str[i] = delimiter;
    i++;
    while (j != my_strlen(src2)) {
        str[i] = src2[j];
        j++;
        i++;
    }
    str[i] = '\0';
    return (str);
}
