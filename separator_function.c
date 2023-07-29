/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-naira.awadin
** File description:
** separator_function
*/

#include "my.h"

void condition_execution(char **env, my_shell *shell, char **sep, int i)
{
    char **cmd = my_str_to_word_array(sep[i]);

    if (cmd != NULL && cmd[0] != NULL) {
        execute_basic_command_sep(env, shell, cmd);
    }

    if (cmd != NULL) {
        for (int j = 0; cmd[j] != NULL; j++) {
            free(cmd[j]);
        }
        free(cmd);
    }
}

void separator_func(char **env, my_shell *shell)
{
    char **sep = word_array_sep(shell->line);
    if (sep != NULL) {
        for (int i = 0; sep[i] != NULL; i++) {
            condition_execution(env, shell, sep, i);
        }
    }
}
