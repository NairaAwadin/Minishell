/*
** EPITECH PROJECT, 2023
** path
** File description:
** path
*/

#include "my.h"

char *print_path(int ac, char **av, char **env, my_shell *shell)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][4] == '=') {
            env[i][4] = ':';
        }
        if (env[i][0] == 'P' && env[i][1] == 'A' &&
            env[i][2] == 'T' && env[i][3] == 'H') {
            shell->buffer = env[i];
        }
    }
    return shell->buffer;
}

char **wordarray_path(my_shell *shell)
{
    int i = 1;
    shell->buf = my_str_to_word_array_path(shell->buffer);
    while (shell->buf[i] != NULL) {
        i++;
    }
    return shell->buf;
}
