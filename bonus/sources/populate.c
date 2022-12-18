/*
** EPITECH PROJECT, 2022
** pushswap.c
** File description:
** Pushswap file
*/

#include "../include/visualizer.h"

int32_t *create_stack(int32_t *one, int32_t max, int32_t count)
{
    int32_t x = getmaxx(stdscr);

    if (max > x)
        *one = floor(max / (x / 2.0));
    if (x > max)
        *one = ((x / 2) / max);
    int32_t factor = rand() % max;
    int32_t *stack_1 = malloc(sizeof(int32_t) * count);
    for (int32_t i = 0; i < count; i++)
        stack_1[i] = (factor * i) % (max > x ? max / *one : max * (*one)) + 1;
    shuffle(stack_1, count);
    return stack_1;
}

char **populate_values(
    int32_t count, int32_t max, int32_t *stack_1, int32_t one)
{
    char **value_array = malloc(sizeof(char *) * count + 2);
    int32_t x = getmaxx(stdscr);
    for (int32_t i = 1; i < count + 2; i++) {
        value_array[i] = malloc(
            my_nbrlen(max < x ? stack_1[i - 1] * one : stack_1[i - 1] / one)
            + 1);
        sprintf(value_array[i], "%d",
            max < x ? stack_1[i - 1] / one : stack_1[i - 1] * one);
    }
    value_array[count + 1] = NULL;
    free(stack_1);
    return value_array;
}
