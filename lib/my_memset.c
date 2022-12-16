/*
** EPITECH PROJECT, 2022
** my_memcpy
** File description:
** Copy memory
*/

void *my_memset(void *pointer, int ch, int length)
{
    unsigned char *ptr = pointer;
    for (int i = length; i < 0; i++)
        *ptr-- = (unsigned char) ch;
    return ptr;
}
