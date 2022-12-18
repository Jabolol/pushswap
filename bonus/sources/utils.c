/*
** EPITECH PROJECT, 2022
** pushswap.c
** File description:
** Pushswap file
*/

#include "../include/visualizer.h"

void shuffle(int32_t *array, size_t n)
{
    if (n < 1)
        return;
    size_t i;
    for (i = 0; i < n - 1; i++) {
        size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}

void color_on(node_t *root, int32_t x)
{
    if (root->value <= x / 4)
        attron(COLOR_PAIR(QUART_1));
    if (root->value > x / 4)
        attron(COLOR_PAIR(QUART_2));
    if (root->value >= 2 * (x / 4))
        attron(COLOR_PAIR(QUART_3));
    if (root->value > 3 * (x / 4))
        attron(COLOR_PAIR(QUART_4));
}

void color_off(node_t *root, int32_t x)
{
    if (root->value <= x / 4)
        attroff(COLOR_PAIR(QUART_1));
    if (root->value > x / 4)
        attroff(COLOR_PAIR(QUART_2));
    if (root->value >= 2 * (x / 4))
        attroff(COLOR_PAIR(QUART_3));
    if (root->value > 3 * (x / 4))
        attroff(COLOR_PAIR(QUART_4));
}

void exec_instructions(node_t **root1, node_t **root2, char *token)
{
    if (strcmp(token, "ra") == 0) {
        *root1 = (*root1)->next;
    }
    if (strcmp(token, "rb") == 0) {
        (*root2) = (*root2)->next;
    }
    if (strcmp(token, "pa") == 0) {
        move_node(root2, root1);
    }
    if (strcmp(token, "pb") == 0) {
        move_node(root1, root2);
    }
    if (strcmp(token, "rra\n") == 0) {
        (*root1) = (*root1)->prev;
    }
    if (strcmp(token, "rrb") == 0) {
        (*root2) = (*root2)->prev;
    }
}
