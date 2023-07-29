/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-naira.awadin
** File description:
** word_array_bin
*/

#include "my.h"

int my_char_isalpha_bin(char c)
{
    if (c == '/')
        return 0;
    else
        return 1;
}

int count_word_bin(char const *str)
{
    int i = 0;
    int count = 0;
    if (str[i] != ' ')
    count = count + 1;

    for (; str[i] != '\0'; i++) {
        if (my_char_isalpha_path(str[i]) == 0 &&
            my_char_isalpha_path(str[i + 1]) == 1)
            count++;
    }
    return (count);
}

int count_letters_bin(char const *str, int i)
{
    int count = 0;
    for (; my_char_isalpha_path(str[i]) == 1; i++) {
        count++;
    }
    return (count);
}

char **my_str_to_word_array_bin(char const *str)
{
    int i = 0;
    int y = 0;
    int x = 0;
    char **buf = malloc(sizeof(char *) * (count_word_path(str) + 1));

    for (; x < count_word_path(str); x++) {
        buf[x] = malloc(sizeof(char) * (count_letters_path(str, i) + 1));
        for (; my_char_isalpha_path(str[i]) == 1; y++) {
            buf[x][y] = str[i];
            i++;
        }
        buf[x][y] = '\0';
        while (my_char_isalpha_path(str[i]) == 0)
            i++;
        y = 0;
    }
    buf[x] = NULL;
    return buf;
}
