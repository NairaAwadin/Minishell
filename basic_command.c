/*
** EPITECH PROJECT, 2023
** minishell_copie2
** File description:
** basic_command
*/

#include "my.h"

char *link_command(char **command, char **env, my_shell *shell)
{
    char *found = NULL;

    if (access(command[0], X_OK) == 0) {
        return command[0];
    }
    for (int i = 1; shell->buf[i] != NULL && found == NULL; i++) {
        shell->tmp = my_strdup_path(shell->buf[i], command[0], '/');
        if (access(shell->tmp, X_OK) == 0) {
            found = shell->tmp;
        }
    }
    return found;
}

void execute_bin(char **env, char **av, my_shell *shell)
{
    char **array_bin = my_str_to_word_array_bin(shell->line);
    int comp = my_strcmp("bin", array_bin[0]);
    if (comp == 0)
        execve(av[0], av, env);
}

int execute_command(char **command, char **env, my_shell *shell)
{
    int pid_t;
    int status;

    pid_t = fork();
    if (pid_t < 0) {
        return -1;
    } else if (pid_t == 0) {
    execve(shell->tmp, command, env);
    execute_bin(env, command, shell);
    return 1;
    }
     else {
        wait(&status);
    }
    return 0;
}

int execute_basic_command_sep(char **env, my_shell *shell, char **cmd)
{
    shell->tmp = link_command(cmd, env, shell);
    if (shell->tmp != NULL) {
        execute_command(cmd, env, shell);
    } else if (my_strcmp(cmd[0], "setenv") != 0) {
        my_putstr(cmd[0]);
        my_putstr(": Command not found.\n");
    }
    return 0;
}
