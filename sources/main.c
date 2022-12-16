/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Pushswap entry point
*/

#include "../include/pushswap.h"

void constructor(void *ptr, ...)
{
    void *fn;
    va_list vl;
    static int32_t offset = 0;

    va_start(vl, ptr);
    while ((fn = va_arg(vl, void *)) && fn) {
        my_memcpy(ptr + offset, &fn, sizeof(fn));
        offset += sizeof(fn);
    }
    va_end(vl);
}

int32_t main(int32_t argc, char **argv)
{
    pushswap_t *class;
    metadata_t *meta = malloc(sizeof(metadata_t));
    node_t *root1 = malloc(sizeof(node_t));
    node_t *root2 = malloc(sizeof(node_t));
    if (argc <= 2) {
        argc == 2 ? write(1, "\n", 1) : -1;
        return argc == 2 ? 0 : 84;
    }
    NEW(pushswap_t, class, class, root1, root2, meta, FUNCTIONS);
    class->parse_array(class, argc, argv);
    class->root1 =
        class->build_list(class, class->meta->stack1, class->meta->length);
    class->quicksort(
        class, class->meta->stack1_ptrs, 0, class->meta->length - 1);
    class->binary_length(class);
    class->radix_sort(class);
    class->destroy(class);
    write(1, "\n", 1);
    return 0;
}
