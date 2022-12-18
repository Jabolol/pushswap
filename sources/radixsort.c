/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Pushswap entry point
*/

#include "../include/pushswap.h"

void binary_length(pushswap_t *self)
{
    for (int32_t bits = MSB; bits >= 0; bits--) {
        if ((self->meta->highest >> bits) & 1) {
            self->meta->binary_len = bits + 1;
            return;
        }
    }
    self->meta->binary_len = 1;
}

void push_or_shift(pushswap_t *self, int32_t bit)
{
    if (((self->root1->value >> bit) & 1) == 0) {
        self->move_node(self, &self->root1, &self->root2);
        write(1, "pb ", 3);
    } else {
        self->root1 = self->root1->next;
        write(1, "ra ", 3);
    }
}

void loop_numbers(pushswap_t *self, int32_t bit)
{
    for (int32_t i = 0; i < self->meta->length && self->root1; i++) {
        self->push_or_shift(self, bit);
        if (self->root1->next == self->root1
            || self->root1 == self->root1->next)
            break;
    }
    for (; self->root2;) {
        self->move_node(self, &self->root2, &self->root1);
        write(1, "pa ", 3);
    }
}

void radix_sort(pushswap_t *self)
{
    if (self->meta->is_sorted)
        return;
    int32_t binary_len = self->meta->binary_len;
    for (int32_t bit = 0; bit < binary_len; bit++)
        loop_numbers(self, bit);
    write(1, "ra rra", 6);
}
