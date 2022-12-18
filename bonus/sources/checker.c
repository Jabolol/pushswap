/*
** EPITECH PROJECT, 2022
** pushswap.c
** File description:
** Pushswap file
*/

#include "../include/visualizer.h"

int32_t sanity_check(int32_t argc, char **argv, int32_t *count, int32_t *max)
{
    struct stat st;
    if (argc < 4) {
        printf("Usage: ./visualizer <count> <max> <binary>\n");
        return EXIT_FAILURE;
    }
    if ((*count = atoi(argv[1])) < 1) {
        printf("You must at least provide 1 as <count>\n");
        return EXIT_FAILURE;
    }
    if ((*max = atoi(argv[2])) <= 0 || *max > INT32_MAX) {
        printf(
            "You must provide a positive <max> smaller than %d\n", INT32_MAX);
        return EXIT_FAILURE;
    }
    if ((lstat(argv[3], &st)) != 0
        || !((st.st_mode > 0) && (S_IEXEC & st.st_mode))) {
        printf("You must provide a valid <binary>\n");
        return EXIT_FAILURE;
    }
    return CONTINUE;
}

void init_screen(void)
{
    initscr();
    start_color();
    raw();
    noecho();
    init_pair(QUART_1, COLOR_CYAN, COLOR_BLACK);
    init_pair(QUART_2, COLOR_BLUE, COLOR_BLACK);
    init_pair(QUART_3, COLOR_GREEN, COLOR_BLACK);
    init_pair(QUART_4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(INFO, COLOR_YELLOW, COLOR_BLACK);
}

int32_t check_dimensions(int32_t count)
{
    int32_t x = 0;
    int32_t y = 0;
    getmaxyx(stdscr, y, x);

    if (count > y) {
        char *message =
            "Your terminal isn't big enough to handle your number count :(";
        char *exit_message = "Press any key to quit";
        mvprintw(y / 2, (x - strlen(message)) / 2, "%s\n", message);
        mvprintw(
            (y / 2) + 2, (x - strlen(exit_message)) / 2, "%s\n", exit_message);
        getch();
        endwin();
        return EXIT_FAILURE;
    }
    return CONTINUE;
}
