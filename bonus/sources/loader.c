/*
** EPITECH PROJECT, 2022
** pushswap.c
** File description:
** Pushswap file
*/

#include "../include/visualizer.h"

void exec_in_child(int32_t *pipes, char *push_swap_path, char **new_argv)
{
    close(pipes[READ_PIPE]);
    dup2(pipes[WRITE_PIPE], STDOUT_FILENO);
    execv(push_swap_path, new_argv);
    close(pipes[WRITE_PIPE]);
    exit(EXIT_SUCCESS);
}

char *get_instructions(char *push_swap_path, char **new_argv)
{
    int32_t pipes[2];
    char buffer[2048];
    char *output = malloc(4096);
    if (pipe(pipes) == -1)
        return NULL;
    pid_t pid = fork();
    if (pid == -1)
        return NULL;
    if (pid == 0)
        exec_in_child(pipes, push_swap_path, new_argv);
    else {
        close(pipes[WRITE_PIPE]);
        while (read(pipes[READ_PIPE], buffer, sizeof(buffer)) > 0) {
            strcat(output, buffer);
            memset(buffer, 0, sizeof(buffer));
        }
        close(pipes[READ_PIPE]);
        return output;
    }
    return NULL;
}

void print_current_action(char *token, int32_t cmd_count, int32_t x, int32_t y)
{
    clear();
    char *msg = malloc(100);
    attron(COLOR_PAIR(INFO));
    sprintf(msg, "Executing %s... (%d ops, %.2f ops/s)",
        strcmp(token, "rra\n") == 0 ? "rra" : token, cmd_count, (1 / .025));
    mvprintw(y - (y / 7),
        8 * ((x - strlen(msg) + ((strcmp(token, "rra\n") == 0) ? 5 : 0)) / 10),
        "%s", msg);
    attroff(COLOR_PAIR(INFO));
    move(0, 0);
    free(msg);
}
