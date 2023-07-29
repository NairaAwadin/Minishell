/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include "my.h"

void shell_term(int ac, char **av, char **env, my_shell *shell)
{
    shell->line = NULL; size_t len = 0;
    int i = 0;
    my_putstr("$> ");
    while (getline(&shell->line, &len, stdin) != -1) {
        shell->line[my_strlen(shell->line)- 1] = '\0';
        shell->buffy = my_str_to_word_array(shell->line);
        my_exit(shell->buffy);
        execute_command_cd_home(shell->buffy, env);
        shell->buffer = print_path(ac, av, env, shell);
        shell->buf = wordarray_path(shell);
        shell->tmp = link_command(shell->buffy, env, shell);
        if (shell->line != NULL) {
            separator_func(env, shell);
        } else {
            return;
        }
        my_putstr("$> ");
    }
    free(shell->line);
}
