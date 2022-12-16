/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Pushswap entry point
*/

#include "../include/pushswap.h"

void swap_pointers(int32_t **ptr_1, int32_t **ptr_2)
{
    *ptr_2 = (int32_t *) ((intptr_t) *ptr_1 ^ (intptr_t) *ptr_2
        ^ (intptr_t) ((*ptr_1 = *ptr_2)));
}

int32_t split(pushswap_t *self, int32_t **array, int32_t low, int32_t high)
{
    int32_t pivot = *array[high];
    int32_t index = low - 1;

    for (int32_t j = low; j <= high - 1; j++)
        if (*array[j] <= pivot)
            self->swap_pointers(&array[++index], &array[j]);
    self->swap_pointers(&array[index + 1], &array[high]);
    return index + 1;
}

void quicksort(pushswap_t *self, int32_t **array, int32_t low, int32_t high)
{
    if (low > high)
        return;
    int32_t pivot_position = self->split(self, array, low, high);
    self->quicksort(self, array, low, pivot_position - 1);
    self->quicksort(self, array, pivot_position + 1, high);
}
