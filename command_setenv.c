/*
** EPITECH PROJECT, 2023
** setenv
** File description:
** stenv
*/
#include "my.h"

int my_char_isalpha_set(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 0;
    else
        return 1;
}

int print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putstr("\n");
    }
    return 0;
}

void check_letters(char **av)
{
    if (my_char_isalpha_set(av[1][0]) == 1) {
            my_putstr("setenv: Variable name must begin with a letter.\n");
            return;
        }
}

void setenv_command(char **env, char **av)
{
    int issetenv = my_strcmp(av[0], "setenv");
    if (issetenv == 0 && av[1] == NULL) {
        print_env(env);
    } else if (issetenv == 0 && av[1] != NULL) {
        if (av[2] != NULL && av[3] == NULL) {
            check_letters(av);
        } else if (av[2] != NULL && av[3] != NULL) {
            my_putstr(av[0]);
            my_putstr(": Too many arguments.\n");
        }
    }
}
