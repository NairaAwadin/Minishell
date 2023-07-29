/*
** EPITECH PROJECT, 2023
** put
** File description:
** put
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        my_putchar(src[i]);
        i++;
    }
    return (0);
}
