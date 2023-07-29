/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-naira.awadin
** File description:
** my_word_array_sep
*/

#include "my.h"

int my_char_isalpha_sep(char c)
{
    if (c == ';' || c == '\0')
        return 0;
    else
        return 1;
}

int count_word_sep(char const *str)
{
    int i = 0;
    int count = 0;

    if (str[i] != '\0' && !my_char_isalpha_sep(str[i])) {
        count++;
    }

    for (; str[i] != '\0'; i++) {
        if (my_char_isalpha_sep(str[i]) && !my_char_isalpha_sep(str[i + 1])
        && str[i + 1] != ' ')
            count++;
    }
    return count;
}

int count_letters_sep(char const *str, int i)
{
    int count = 0;
    for (; my_char_isalpha_sep(str[i]) == 1; i++) {
        count++;
    }
    return (count);
}

char **word_array_sep(char const *str)
{
    int i = 0, y = 0, x = 0;
    char **buf = malloc(sizeof(char *) * (count_word_sep(str) + 1));

    while (!my_char_isalpha_sep(str[i]) && str[i] != '\0')
        i++;

    for (; x < count_word_sep(str); x++) {
        buf[x] = malloc(sizeof(char) * (count_letters_sep(str, i) + 1));
        for (; my_char_isalpha_sep(str[i]) == 1; y++) {
            buf[x][y] = str[i];
            i++;
        }
        buf[x][y] = '\0';
        while (!my_char_isalpha_sep(str[i]) && str[i] != '\0') {
            i++;
        }
        y = 0;
    }
    buf[x] = NULL;
    return buf;
}
