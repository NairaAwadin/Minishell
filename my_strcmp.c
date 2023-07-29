/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-naira.awadin
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(const char *str1, const char *str2)
{
    int i = 0;
    int res = 0;

    while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') {
        i++;
    }
    res = str1[i] - str2[i];
    return res;
}
