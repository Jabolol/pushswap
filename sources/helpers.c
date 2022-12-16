/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Pushswap entry point
*/

#include "../include/pushswap.h"

void parse_array(pushswap_t *self, int32_t argc, char **argv)
{
    self->meta->stack1 = malloc(sizeof(int32_t) * argc - 1);
    self->meta->stack1_ptrs = malloc(sizeof(int32_t *) * argc - 1);
    self->meta->length = argc - 1;

    for (int32_t i = 1; i < argc; i++) {
        self->meta->stack1[i - 1] = my_getnbr(argv[i]);
        self->meta->stack1_ptrs[i - 1] = &self->meta->stack1[i - 1];
    }
    free(self->root1);
    free(self->root2);
    self->root2 = NULL;
}

node_t *build_list(pushswap_t *self, int32_t *arr, int32_t length)
{
    node_t *head = NULL;
    node_t *tail = NULL;
    node_t *aux = NULL;
    int32_t highest = arr[0];

    for (int32_t i = 0; i < length; i++) {
        arr[i] > highest ? highest = arr[i] : 0;
        aux = self->create_node(tail, NULL, arr[i]);
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
    self->meta->highest = highest;
    return head;
}

void free_list(node_t *root)
{
    if (!root || !root->next)
        return;
    node_t *temp = root;
    node_t *aux = NULL;
    while (temp->next != root) {
        aux = temp->next;
        free(temp);
        temp = aux;
    }
    free(temp);
}

void destroy(pushswap_t *self)
{
    self->free_list(self->root1);
    self->free_list(self->root2);
    free(self->meta->stack1);
    free(self->meta->stack1_ptrs);
    free(self->meta);
    free(self);
}
