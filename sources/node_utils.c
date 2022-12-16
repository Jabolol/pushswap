/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Pushswap entry point
*/

#include "../include/pushswap.h"

node_t *create_node(node_t *next, node_t *prev, int32_t data)
{
    struct node *node = malloc(sizeof(node_t));
    node->next = next;
    node->prev = prev;
    node->value = data;
    return node;
}

void remove_node(node_t **node)
{
    if (!node || !*node)
        return;
    if ((*node) == (*node)->next)
        *node = NULL;
    else {
        (*node)->next->prev = (*node)->prev;
        (*node)->prev->next = (*node)->next;
        (*node) = (*node)->next;
    }
}

void update_big_list(node_t *temp, node_t **dest)
{
    temp->prev = (*dest)->prev;
    (*dest)->prev = temp;
    temp->next = (*dest);
    temp->prev->next = temp;
    temp->next->prev = temp;
    (*dest) = (*dest)->prev;
}

void move_node(pushswap_t *self, node_t **source, node_t **dest)
{
    if (!source || !*source || source == dest)
        return;
    node_t *temp = *source;
    self->remove_node(source);
    if (!*dest) {
        temp->next = temp;
        temp->prev = temp;
        *dest = temp;
    } else if ((*dest) == (*dest)->next) {
        temp->next = (*dest);
        temp->prev = (*dest);
        (*dest)->next = temp;
        (*dest)->prev = temp;
        (*dest) = (*dest)->next;
    } else
        update_big_list(temp, dest);
}
