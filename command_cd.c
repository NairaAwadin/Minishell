/*
** EPITECH PROJECT, 2023
** cd
** File description:
** cd
*/

#include "my.h"

char *path_home(char **env)
{
    char *buffer_home;
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'H' && env[i][1] == 'O' &&
            env[i][2] == 'M' && env[i][3] == 'E') {
            buffer_home = env[i];
        }
    }
    return buffer_home;
}

void command_cd_home(char **av, char **env)
{
    char *home_path = path_home(env);
    char **home_dir = my_str_to_word_array_path(home_path);
    struct stat st;

    if (home_dir == NULL || home_dir[1] == NULL) {
        return;
    }

    if (stat(home_dir[1], &st) == 0 && S_ISDIR(st.st_mode)) {
        chdir(home_dir[1]);
    } else {
        my_putstr(home_dir[1]);
        my_putstr(": Not a directory. \n");
    }
}

int cond_cd(char **av)
{
    if (av[1] != NULL) {
            if (av[2] != NULL) {
                my_putstr(av[0]);
                my_putstr(": Too many arguments.\n");
                return 1;
            }
        }
}

int execute_command_cd_home(char **av, char **env)
{
    if (my_strcmp(av[0], "cd") == 0) {
        cond_cd(av);
        cd_error_message(av, env);
        return 1;
    } else {
        return 0;
    }
}

int cd_error_message(char **av, char **env)
{
    struct stat st;

    if (av[1] == NULL || my_strcmp(av[1], "~") == 0) {
        command_cd_home(av, env);
        return 0;
    }

    if (access(av[1], F_OK) != 0) {
        my_putstr(av[1]);
        my_putstr(": No such file or directory.\n");
    } else if (stat(av[1], &st) != 0 || !S_ISDIR(st.st_mode)) {
        my_putstr(av[1]);
        my_putstr(": Not a directory.\n");
        return 0;
    } else {
        chdir(av[1]);
    }

    return 0;
}
