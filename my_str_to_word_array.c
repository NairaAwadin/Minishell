/*
** EPITECH PROJECT, 2022
** str to word array
** File description:
** str to word array
*/

#include "my.h"

int my_char_isalpha(char c)
{
    if (c == '\n' || c == ' ' || c == '\t' || c == '\0')
        return 0;
    else
        return 1;
}

int count_letters(char const *str, int i)
{
    int count = 0;
    for (; my_char_isalpha(str[i]) == 1; i++) {
        count++;
    }

    return (count);
}

int count_words(char const *str)
{
    int i = 0;
    int word_count = 0;

    while (str[i] == '\t') {
        i++;
    }

    if (str[i] != ' ') {
        word_count = 1;
    }

    for (; str[i] != '\0'; i++) {
        if (my_char_isalpha(str[i]) == 0 && my_char_isalpha(str[i + 1]) == 1) {
            word_count++;
        }
    }

    return word_count;
}

void fill_word_array(char const *str, char **buf, int word_count)
{
    int i = 0; int x = 0; int y = 0;
    while (str[i] == ' ' || str[i] == '\t') {
        i++;
    }
    for (; x < word_count; x++) {
        while (str[i] == ' ' || str[i] == '\t') {
            i++;
        }
        int word_length = count_letters(str, i);
        buf[x] = malloc(sizeof(char) * (word_length + 1));
        if (buf[x] == NULL)
            return;
        for (; my_char_isalpha(str[i]) == 1; i++, y++) {
            buf[x][y] = str[i];
        }
        buf[x][y] = '\0'; y = 0;
    } buf[x] = NULL;
    for (int j = x + 1; j < word_count; j++) {
        free(buf[j]);
    }
}

char **my_str_to_word_array(char const *str)
{
    int word_count = count_words(str);
    char **buf = malloc(sizeof(char *) * (word_count + 1));
    if (buf == NULL)
        return NULL;
    fill_word_array(str, buf, word_count);
    return buf;
}
