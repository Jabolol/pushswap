/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Pushswap entry point
*/

#include <stdint.h>
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/pushswap.h"

Test(test, hello)
{
    cr_assert_str_eq("hello", "hello");
}

pushswap_t *create_class(void)
{
    pushswap_t *class;
    metadata_t *meta = malloc(sizeof(metadata_t));
    node_t *root1 = malloc(sizeof(node_t));
    node_t *root2 = malloc(sizeof(node_t));
    NEW(pushswap_t, class, class, root1, root2, meta, FUNCTIONS);
    return class;
}

Test(parse_array, parse_the_array)
{
    pushswap_t *class = create_class();
    char **argv = malloc(sizeof(char *) * 4);
    argv[1] = "1";
    argv[2] = "3";
    argv[3] = "2";
    class->parse_array(class, 4, argv);
    free(argv);
    cr_assert_eq(class->meta->is_sorted, false);
    cr_assert_eq(class->meta->stack1[0], 1);
    cr_assert_eq(class->meta->stack1[1], 3);
    cr_assert_eq(class->meta->stack1[2], 2);
    cr_assert_eq(class->meta->length, 3);
    class->destroy(class);
}

Test(create_list, create_a_list)
{
    pushswap_t *class = create_class();
    int32_t *argv = malloc(sizeof(int32_t) * 4);
    argv[1] = 1;
    argv[2] = 3;
    argv[3] = 2;
    class->build_list(class, NULL, 3);
    cr_assert_eq(class->meta->highest, 3);
    cr_assert_eq(class->root1->value, 1);
    cr_assert_eq(class->root1->next->value, 3);
    cr_assert_eq(class->root1->prev->value, 2);
    class->destroy(class);
}

Test(create_node, create_a_node)
{
    node_t *new_node = create_node(NULL, NULL, 69);
    cr_assert_null(new_node->next);
    cr_assert_null(new_node->prev);
    cr_assert_eq(new_node->value, 69);
    free(new_node);
}

Test(remove_node, remove_a_node)
{
    node_t *new_node = create_node(NULL, NULL, 69);
    node_t *aux = new_node;
    new_node->next = new_node;
    new_node->prev = new_node;
    remove_node(&new_node);
    cr_assert_null(new_node);
    free(aux);
}

Test(move_node, move_a_node)
{
    node_t *node_1 = create_node(NULL, NULL, 69);
    node_1->next = create_node(NULL, node_1, 420);
    node_1->prev = create_node(node_1, NULL, 78);
    node_1->next->next = node_1->prev;
    node_1->prev->prev = node_1->next;
    node_t *new_node = NULL;
    move_node(create_class(), &node_1, &new_node);
    cr_assert_not_null(new_node);
    cr_assert_not_null(node_1->next);
    cr_assert_not_null(node_1->prev);
    cr_assert_eq(node_1->prev, node_1->next);
    free_list(node_1);
    free_list(new_node);
}

Test(swap_pointers, swap_two_pointers)
{
    int32_t *one = malloc(sizeof(int32_t));
    int32_t *aux = one;
    int32_t *two = malloc(sizeof(int32_t));
    swap_pointers(&one, &two);
    cr_assert_eq(two, aux);
    cr_assert_not_null(one);
    free(one);
    free(two);
}

Test(quick_sort, sort_an_array)
{
    pushswap_t *class = create_class();
    class->meta->is_sorted = false;
    int32_t *array = malloc(sizeof(int32_t) * 4);
    array[0] = 2;
    array[1] = 1;
    array[2] = 4;
    array[3] = 3;
    quicksort(class, &array, 1, 4);
    cr_assert_eq(array[0], 1);
    cr_assert_eq(array[1], 2);
    cr_assert_eq(array[2], 3);
    cr_assert_eq(array[3], 4);
    free(array);
    class->destroy(class);
}

Test(radix_sort, sort_by_radix_algo, .init = cr_redirect_stdout)
{
    pushswap_t *class = create_class();
    class->meta->is_sorted = false;
    class->meta->highest = 20;
    class->meta->length = 5;
    int32_t *array = malloc(sizeof(int32_t) * 5);
    array[0] = 2;
    array[1] = 1;
    array[2] = 4;
    array[3] = 20;
    array[4] = 3;
    binary_length(class);
    cr_assert_eq(class->meta->binary_len, 5);
    build_list(class, array, 5);
    cr_assert_not_null(class->root1);
    cr_assert_null(class->root2);
    cr_assert_stdout_eq_str(
        "pb ra pb pb ra pa pa pa ra pb pb pb ra pa pa pa ra ra pb pb pb pa pa "
        "pa pb pb pb pb pa pa pa pa pb pb pb pb pa pa pa pa ra rra");
    radix_sort(class);
    class->destroy(class);
}
