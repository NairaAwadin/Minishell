/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <string.h>

typedef struct my_shell_s {
    char *line;
    char **buffy;
    char *buffer;
    char **buf;
    char *tmp;
    char **copy_env;
}my_shell;

void my_putchar (char c);
int my_putstr(char const *str);
int my_strcmp(const char *str1, const char *str2);
int my_strlen(char const *str);
char *my_strdup ( char const * src);
char *my_strdup_path(char const *src1, char const *src2, char delimiter);

int my_char_isalpha(char c);
int my_char_isalpha_path(char c);
int count_word(char const *str);
int count_word_path(char const *str);
int count_letters(char const *str, int i);
int count_letters_path(char const *str, int i);
char **my_str_to_word_array(char const *str);
char **my_str_to_word_array_path(char const *str);
char **word_array_sep(char const *str);

void shell_term(int ac, char **av, char **env, my_shell *shell);

char *print_path(int ac, char **av, char **env, my_shell *shell);
char **wordarray_path(my_shell *shell);
char *link_command(char **command, char **env, my_shell *shell);
int execute_command (char **command, char **env, my_shell *shell);
int execute_basic_command_sep(char **env, my_shell *shell, char **cmd);
void separator_func(char **env, my_shell *shell);

char *path_home(char **env);
void command_cd_home(char **av, char **env);
int execute_command_cd_home(char **av, char **env);
int cd_error_message(char **av, char **env);

void my_exit(char **av);

char **copy_env(char **env);

int print_env(char **env);
void setenv_command(char **env, char **av);
char **my_str_to_word_array_bin(char const *str);

#endif
