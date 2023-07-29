/*
** EPITECH PROJECT, 2023
** copie env
** File description:
** copie env
*/

#include "my.h"

char **copy_env(char **env)
{
    int i;
    for (i = 0; env[i] != NULL; i++);
    char **copy_env = malloc(sizeof(char *) * (i + 1));

    for (int j = 0; j < i; j++) {
        copy_env[j] = my_strdup(env[j]);
    }
    copy_env[i] = NULL;
    return copy_env;
}
