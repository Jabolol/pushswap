/*
** EPITECH PROJECT, 2022
** pushswap.c
** File description:
** Pushswap file
*/

#ifndef __PSWAP_VIS
    #define __PSWAP_VIS
    #include <fcntl.h>
    #include <math.h>
    #include <ncurses.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <time.h>
    #include <unistd.h>

    typedef struct node node_t;
    typedef struct node {
        int32_t value;
        node_t *next;
        node_t *prev;
    } node_t;

    #define QUART_1    1
    #define QUART_2    2
    #define QUART_3    3
    #define QUART_4    4
    #define INFO       5
    #define CONTINUE   0
    #define ASCII_CHAR '@'
    #define READ_PIPE  0
    #define WRITE_PIPE 1

int32_t my_nbrlen(long signed number);
node_t *create_node(node_t *next, node_t *prev, int32_t data);
node_t *build_list(int32_t *arr, int32_t length);
void remove_node(node_t **node);
void update_big_list(node_t *temp, node_t **dest);
void move_node(node_t **source, node_t **dest);
void free_list(node_t *root);
char *get_instructions(char *push_swap_path, char **new_argv);
void shuffle(int32_t *array, size_t n);
int32_t sanity_check(int32_t argc, char **argv, int32_t *count, int32_t *max);
void init_screen(void);
int32_t check_dimensions(int32_t count);
char **populate_values(
    int32_t count, int32_t max, int32_t *stack_1, int32_t one);
int32_t *create_stack(int32_t *one, int32_t max, int32_t count);
void color_on(node_t *root, int32_t x);
void color_off(node_t *root, int32_t x);
void exec_instructions(node_t **root1, node_t **root2, char *token);
void traverse_list(node_t *root, int32_t *x, int32_t offset, int32_t pos);
void event_loop(char **argv, char **value_array, node_t *root1);
void print_current_action(
    char *token, int32_t cmd_count, int32_t x, int32_t y);
#endif
