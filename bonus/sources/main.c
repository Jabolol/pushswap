/*
** EPITECH PROJECT, 2022
** pushswap.c
** File description:
** Pushswap file
*/

#include "../include/visualizer.h"

int main(int argc, char **argv)
{
    int32_t count = 0;
    int32_t max = 0;
    srand(time(NULL));
    if (sanity_check(argc, argv, &count, &max) != CONTINUE)
        return EXIT_FAILURE;
    init_screen();
    if (check_dimensions(count) != CONTINUE)
        return EXIT_FAILURE;
    int32_t one = 0;
    int32_t *stack_1 = create_stack(&one, max, count);
    node_t *root1 = build_list(stack_1, count);
    char **value_array = populate_values(count, max, stack_1, one);
    value_array[0] = argv[3];
    event_loop(argv, value_array, root1);
    getch();
    endwin();
    for (int32_t i = 1; i < count + 1; i++)
        free(value_array[i]);
    free(value_array);
    return EXIT_SUCCESS;
}
