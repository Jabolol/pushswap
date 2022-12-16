/*
** EPITECH PROJECT, 2022
** my_sokoban.c
** File description:
** My sokoban file
*/

#ifndef __PSWAP
    #define __PSWAP
    #include <stdarg.h>
    #include <stddef.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>

    #define NEW(type_t, class_ptr, ...)                  \
        ({                                               \
            class_ptr = malloc(sizeof(type_t));          \
            my_memset(class_ptr, 0, sizeof(*class_ptr)); \
            constructor(class_ptr, __VA_ARGS__);         \
        })

    #define FUNCTIONS                                    \
        &parse_array, &check_sorted, &build_list,        \
        &swap_pointers, &split, &quicksort, &free_list,  \
        &binary_length, &create_node, &remove_node,      \
        &move_node, &loop_numbers, &push_or_shift,       \
        &radix_sort, &destroy, NULL

typedef struct node node_t;
typedef struct pushswap pushswap_t;

typedef struct node {
    int32_t value;
    node_t *next;
    node_t *prev;
} node_t;

typedef struct metadata {
    int32_t *stack1;
    int32_t **stack1_ptrs;
    int32_t highest;
    int32_t binary_len;
    int32_t length;
    bool is_sorted;
} metadata_t;

typedef struct pushswap {
    /* PROPERTIES */
    pushswap_t *self;
    node_t *root1;
    node_t *root2;
    metadata_t *meta;

    /* METHODS */
    void (*parse_array)(pushswap_t *, int32_t, char **);
    void (*check_sorted)(pushswap_t *self);
    node_t *(*build_list)(pushswap_t *, int32_t *, int32_t);
    void (*swap_pointers)(int32_t **, int32_t **);
    int32_t (*split)(pushswap_t *, int32_t **, int32_t, int32_t);
    void (*quicksort)(pushswap_t *, int32_t **, int32_t, int32_t);
    void (*free_list)(node_t *);
    void (*binary_length)(pushswap_t *);
    node_t *(*create_node)(node_t *, node_t *, int32_t);
    void (*remove_node)(node_t **);
    void (*move_node)(pushswap_t *, node_t **, node_t **);
    void (*loop_numbers)(pushswap_t *self, int32_t bit);
    void (*push_or_shift)(pushswap_t *, int32_t);
    void (*radix_sort)(pushswap_t *);
    void (*destroy)(pushswap_t *);
} pushswap_t;

void constructor(void *ptr, ...);
void *my_memset(void *pointer, int32_t ch, int32_t length);
void *my_memcpy(void *dest, const void *src, int32_t size);
void swap_pointers(int32_t **ptr_1, int32_t **ptr_2);
int32_t split(pushswap_t *self, int32_t **array, int32_t low, int32_t high);
void quicksort(pushswap_t *self, int32_t **array, int32_t low, int32_t high);
node_t *create_node(node_t *next, node_t *prev, int32_t data);
void remove_node(node_t **node);
void move_node(pushswap_t *self, node_t **source, node_t **dest);
void binary_length(pushswap_t *self);
void push_or_shift(pushswap_t *self, int32_t bit);
void radix_sort(pushswap_t *self);
void parse_array(pushswap_t *self, int32_t argc, char **argv);
node_t *build_list(pushswap_t *self, int32_t *arr, int32_t length);
void loop_numbers(pushswap_t *self, int32_t bit);
void free_list(node_t *root);
void destroy(pushswap_t *self);
int my_getnbr(char const *str);
void check_sorted(pushswap_t *self);
#endif
