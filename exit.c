/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-naira.awadin
** File description:
** exit
*/

#include "my.h"

void my_exit(char **av)
{
    if (my_strcmp(av[0], "exit") == 0 && av[1] == NULL)
        exit(0);
}
