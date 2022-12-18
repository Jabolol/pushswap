/*
** EPITECH PROJECT, 2022
** pushswap.c
** File description:
** Pushswap file
*/

#include "../include/visualizer.h"

void traverse_list(node_t *root, int32_t *x, int32_t offset, int32_t pos)
{
    int32_t out = 0;
    move(out, pos);
    node_t *temp = root;
    while (true) {
        *x = getmaxx(stdscr);
        if (root) {
            color_on(root, offset);
            hline(ASCII_CHAR, root->value);
            color_off(root, offset);
            root = root->next;
            out = out + 1;
        }
        move(out, pos);
        refresh();
        if (root == temp)
            break;
    }
}

void event_loop(char **argv, char **value_array, node_t *root1)
{
    int32_t x = 0;
    int32_t y = 0;
    node_t *root2 = NULL;
    char *out_buff = get_instructions(argv[3], value_array);
    char *token = NULL;
    int32_t cmd_count = 0;
    getmaxyx(stdscr, y, x);
    while ((token = strsep(&out_buff, " "))) {
        cmd_count = cmd_count + 1;
        exec_instructions(&root1, &root2, token);
        print_current_action(token, cmd_count, x, y);
        traverse_list(root1, &x, x / 2, 0);
        traverse_list(root2, &x, x, x / 2);
        usleep(.025 * 1e6);
    }
    free_list(root1);
    free(out_buff);
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
