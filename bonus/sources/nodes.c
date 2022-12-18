/*
** EPITECH PROJECT, 2022
** pushswap.c
** File description:
** Pushswap file
*/

#include "../include/visualizer.h"

node_t *create_node(node_t *next, node_t *prev, int32_t data)
{
    struct node *node = malloc(sizeof(node_t));
    node->next = next;
    node->prev = prev;
    node->value = data;
    return node;
}

node_t *build_list(int32_t *arr, int32_t length)
{
    node_t *head = NULL;
    node_t *tail = NULL;
    node_t *aux = NULL;
    int32_t highest = arr[0];

    for (int32_t i = 0; i < length; i++) {
        arr[i] > highest ? highest = arr[i] : 0;
        aux = create_node(tail, NULL, arr[i]);
        if (i == 0)
            head = aux;
        else {
            tail->next = aux;
            aux->prev = tail;
        }
        tail = aux;
    }
    head->prev = tail;
    tail->next = head;
    return head;
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

void move_node(node_t **source, node_t **dest)
{
    if (!source || !*source || source == dest)
        return;
    node_t *temp = *source;
    remove_node(source);
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
