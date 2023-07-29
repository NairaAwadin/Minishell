/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av, char **env)
{
    my_shell *shell = malloc (sizeof(my_shell));

    shell_term(ac, av, env, shell);
    return 0;
}
